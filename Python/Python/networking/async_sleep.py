# async/await syntax

import asyncio

async def task():
    print("Start")
    await asyncio.sleep(1)
    print("Finish")


async def main():
    task1 = asyncio.create_task(task())
    task2 = asyncio.create_task(task())
    task3 = asyncio.create_task(task())

    await asyncio.sleep(1)
    # cnt = 0
    # for i in range(100000000):
    #     cnt += i


    await asyncio.gather(task1, task2, task3)

asyncio.run(main())