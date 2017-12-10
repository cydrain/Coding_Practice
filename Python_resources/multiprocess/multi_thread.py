import time, threading, multiprocessing

### Test 1 ####################################################################

def loop():
    print('thread %s is running...' % threading.current_thread().name)
    n = 0
    while n < 5:
        n = n + 1
        print('thread %s >>> %s' % (threading.current_thread().name, n))
        time.sleep(1)
    print('thread %s ended.' % threading.current_thread().name)

def test1():
    print('thread %s is running...' % threading.current_thread().name)
    t = threading.Thread(target=loop, name='LoopThread')
    t.start()
    t.join()
    print('thread %s ended.' % threading.current_thread().name)

### Test 2 ####################################################################

balance = 0
lock = threading.Lock()

def change_it(n):
    global balance
    balance = balance + n
    balance = balance - n

def run_thread(n):
    for i in range(1000000):
        lock.acquire()
        change_it(n)
        lock.release()

def test2():
    t1 = threading.Thread(target=run_thread, args=(5,))
    t2 = threading.Thread(target=run_thread, args=(8,))
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(balance)

### Test 3 ####################################################################

def deadLoop():
    x = 0
    while True:
        x = x ^ 1

def test3():
    for i in range(multiprocessing.cpu_count()):
        t = threading.Thread(target=deadLoop)
        t.start()

### Test 4 ####################################################################

local_school = threading.local()

def process_student():
    std = local_school.student
    print('Hello, %s (in %s)' % (std, threading.current_thread().name))

def process_thread(name):
    local_school.student = name
    process_student()

def test4():
    t1 = threading.Thread(target=process_thread, args=('Alice',), name='Thread-A')
    t2 = threading.Thread(target=process_thread, args=('Bob',), name='Thread-B')
    t1.start()
    t2.start()
    t1.join()
    t2.join()

### Main ######################################################################
if __name__ == '__main__':
    test_list = [test1, test2, test3, test4]
    while True:
        print('')
        n = int(raw_input('Which test do you want to run: '))
        try:
            test_list[n-1]()
        except:
            print('Wrong input!')
        time.sleep(1)

