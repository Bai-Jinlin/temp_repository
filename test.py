#!/usr/bin/env python

import myasync


def compute(x, y):
    r=yield from myasync.sleep(1,222)
    print(r)
    return x + y


def print_sum(x, y):
    result = yield from compute(x, y)
    print("%s + %s = %s" % (x, y, result))


loop = myasync.get_event_loop()
loop.run_until_complete(print_sum(1, 2))
