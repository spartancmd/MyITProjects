
# sync networking approach

if 0: # not to waste time
    import requests

    def get_content(url):
        return requests.get(url).text

    cnt = 30
    for i in range(cnt):
        get_content("http://example.org")

# async approach (python 3.5+)

# asyncio library
# async/await syntax

import asyncio

# coroutine
async def f():
    print("A")
    await asyncio.sleep(1) # network operation
    print("B")
    return 0

async def g():
    print("a")
    await asyncio.sleep(2) # network operation
    print("b")
    return 1

async def h():
    print("-")
    await asyncio.sleep(2) # network operation
    print("_")
    return 2


async def main():
    task1 = asyncio.create_task(f())
    print("After task1 scheduling")
    task2 = asyncio.create_task(g())
    print("After task2 scheduling")
    task3 = asyncio.create_task(h())
    print("After task3 scheduling")

    print(await task1)
    print(await task2)
    print(await task3)
    # await asyncio.gather(task1, task2, task3)

# asyncio.run(main())


# async network approach

import aiohttp

async def make_request(task_num, url):
    # await asyncio.sleep(2)
    # print(task_num)
    print("Make request beginning")
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            print(task_num, resp.status)

async def main():
    cnt = 100
    tasks = []

    for i in range(cnt):
        # await make_request(i, "http://example.org")
        tasks.append(
            asyncio.create_task(make_request(i, "http://example.org"))
        )

    print("awaiting all tasks!")

    # await asyncio.sleep(1)

    await asyncio.gather(*tasks) # wait for all tasks to be completed

# asyncio.run(main())


# generators and coroutines


async def task():
    print("Start")
    await asyncio.sleep(1)
    print("Finish")


async def main():
    task1 = asyncio.create_task(task())
    task2 = asyncio.create_task(task())
    task3 = asyncio.create_task(task())

    await asyncio.gather(task1, task2, task3)

asyncio.run(main())
