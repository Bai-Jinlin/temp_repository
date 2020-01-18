#!/usr/bin/env python3
import asyncio


async def compute(x, y):
    r=await asyncio.sleep(1,222)
    print(r)
    return x + y


async def print_sum(x, y):
    result = await compute(x, y)
    print("%s + %s = %s" % (x, y, result))


loop = asyncio.get_event_loop()
loop.run_until_complete(print_sum(1, 2))
