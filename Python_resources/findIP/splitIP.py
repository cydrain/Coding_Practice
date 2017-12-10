__author__ = "Cai Yudong (cydrain@gmail.com)"
__data__ = "$Date: 2013/09/24 $"

import time

def splitIPAddr(fileLocation, targetDir):
    read_handler = open(fileLocation, 'r')
    write_handlers = [0] * 10
    for i in range(10):
        write_handlers[i] = open(targetDir+"/file_"+str(i)+".txt", 'a+')

    i = 0
    print time.ctime()
    while (True):
        line = read_handler.readline()
        if not line:
            break
        if (i % 10000000 == 0):
            print "  " + str(i) + ": " + time.ctime()
        ip = line.split('.')
        write_handlers[int(ip[3])%10].write(line)
        i += 1

    for i in range(10):
        write_handlers[i].close()
    read_handler.close()


if __name__ == '__main__':
    print "Start: " + str(time.ctime())
    splitIPAddr("massiveIP.txt", "massiveData")
    print "End: " + str(time.ctime())
