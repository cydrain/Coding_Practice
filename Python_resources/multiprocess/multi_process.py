import os, time, random, subprocess
from multiprocessing import Process, Pool, Queue

### Test 1 ####################################################################
def test1():
    print('Process (%s) start ...' % os.getpid())

    pid = os.fork()
    if pid == 0:
        print('I am child process (%s), my parent is %s.' % (os.getpid(), os.getppid()))
    else:
        print('I (%s) just create a child process (%s).' % (os.getpid(), pid))

### Test 2 ####################################################################

# child process
def run_proc(name):
    print('Run child process %s (%s) ...' % (name, os.getpid()))

def test2():
    print('Parent process %s.' % os.getpid())
    p = Process(target = run_proc, args = ('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')

### Test 3 ####################################################################

def long_time_task(name):
    print('Run task %s (%s) ...' % (name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task %s runs %0.2f seconds.' % (name, (end-start)))

def test3():
    print('Parent process %s.' % os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task, args=(i,))
    print('Waiting for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')

### Test 4 ####################################################################

def test4():
    print('$ nslookup www.python.org')
    r = subprocess.call(['nslookup', 'www.python.org'])
    print('Exit code: ', r)

### Test 5 ####################################################################

def test5():
    print('$ nslookup')
    p = subprocess.Popen(['nslookup'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, err = p.communicate(b'set q=mx\npython.org\nexit\n')
    print(output.decode('utf-8'))
    print('Exit code: ', p.returncode)

### Test 6 ####################################################################

def write(q):
    print('Process to write: %s' % os.getpid())
    for value in ['A', 'B', 'C']:
        print('Put %s to queue ...' % value)
        q.put(value)
        time.sleep(random.random())

def read(q):
    print('Process to read: %s' % os.getpid())
    while True:
        value = q.get(True)
        print('Get %s from queue.' % value)

def test6():
    # parent process creates Queue, and transfer to each child process
    q = Queue()
    pw = Process(target=write, args=(q,))
    pr = Process(target=read, args=(q,))
    pw.start()
    pr.start()
    pw.join()
    pr.terminate()

### Main ######################################################################
if __name__ == '__main__':
    test_list = [test1, test2, test3, test4, test5, test6]
    while True:
        print('')
        n = int(raw_input('Which test do you want to run: '))
        try:
            test_list[n-1]()
        except:
            print('Wrong input!')
        time.sleep(1)

