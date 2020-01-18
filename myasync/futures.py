__all__=('set_future_result','Future')
from .handles import Handle
from .eventloops import get_event_loop

def set_future_result(fut, result):
    fut.set_result(result)

class Future:

    _FINISHED = 'finished'
    _PENDING = 'pending'
    _CANCELLED = 'CANCELLED'

    def __init__(self, loop=None):
        if loop is None:
            self._loop = get_event_loop() # 获取当前的 eventloop
        else:
            self._loop = loop
        self._callbacks = []
        self.status = self._PENDING
        self._blocking = False
        self._result = None

    def _schedule_callbacks(self):
        # 将回调函数添加到事件队列里，eventloop 稍后会运行
        for callbacks in self._callbacks:
            self._loop.add_ready(callbacks)
        self._callbacks = []

    def set_result(self, result):
        self.status = self._FINISHED
        self._result = result
        self._schedule_callbacks()  # future 完成后，执行回调函数

    def add_done_callback(self, callback, *args):
        # 为 future 增加回调函数
        if self.done():
            self._loop.call_soon(callback, *args)
        else:
            handle = Handle(callback, self._loop, *args)
            self._callbacks.append(handle)

    def done(self):
        return self.status != self._PENDING

    def result(self):
        if self.status != self._FINISHED:
            raise InvalidStateError('future is not ready')
        return self._result

    def __iter__(self):
        if not self.done():
            self._blocking = True
        yield self
        assert self.done(), 'future not done'
        return self.result()
