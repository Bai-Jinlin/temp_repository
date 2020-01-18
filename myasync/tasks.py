from .futures import set_future_result, Future

__all__ = ('sleep', 'Task', 'ensure_task')


def sleep(delay, result=None, loop=None):
    if delay == 0:
        yield
        return result
    future = Future(loop=loop)
    future._loop.call_later(delay, set_future_result, future, result)
    yield from future


def ensure_task(coro_or_future, loop=None):
    if isinstance(coro_or_future, Future):
        return coro_or_future
    else:
        task = Task(coro_or_future, loop)
    return task


class Task(Future):

    def __init__(self, coro, loop=None):
        super().__init__(loop=loop)
        self._coro = coro    # 协程
        self._loop.call_soon(self._step)  # 启动协程

    def _step(self, exc=None):
        try:
            if exc is None:
                result = self._coro.send(None)
            else:
                result = self._coro.throw(exc)   # 有异常，则抛出异常
        except StopIteration as exc:   # 说明协程已经执行完毕，为协程设置值
            self.set_result(exc.value)
        else:
            if isinstance(result, Future):
                if result._loop is not self._loop:
                    self._loop.call_soon(
                        self._step, RuntimeError('future 与 task 不在同一个事件循环'))
                elif result._blocking:
                    self._blocking = False
                    result.add_done_callback(self._wakeup, result)
                    # 在这个地方为阻塞的 future 添加了 回调函数。
                else:
                    self._loop.call_soon(
                        self._step, RuntimeError('你是不是用了 yield 才导致这个error?')
                    )
            elif result is None:
                self._loop.call_soon(self._step)
            else:
                self._loop.call_soon(self._step, RuntimeError('你产生了一个不合规范的值'))

    def _wakeup(self, future):
        try:
            future.result()  # 查看future 运行是否有异常
        except Exception as exc:
            self._step(exc)
        else:
            self._step()
