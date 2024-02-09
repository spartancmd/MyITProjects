
# without async/await syntax
# let's write our own asyncio.sleep

# here is an example of cooperative multitasking

import time

def sleep(t):
    beginning_time = time.time()

    while time.time() - beginning_time < t:
        yield

def task():
    print("Start")
    yield from sleep(1)
    print("Finish")


# tasks is a queue
# we take from beginning of queue
# we put to the end of queue
def main():
    tasks = [task(), task(), task()]

    while tasks != []:
        cur_task = tasks[0]
        tasks.pop(0) # remove element 0
        try:
            next(cur_task)
        except StopIteration:
            pass # task is done
        else:
            # task is not done yet
            tasks.append(cur_task)

main()
