__author__ = "Cai Yudong (cydrain@gmail.com)"
__data__ = "$Date: 2013/09/24 $"
import random
import time

def generateIP():
    #a = str(random.randrange(10, 255, 10))
    #b = str(random.randrange(0, 255, 3))
    c = str(random.randint(0, 255))
    d = str(random.randint(0, 255))
    return '192.168.'+c+'.'+d

def generateMassiveIPAddr(fileLocation, numOfLines):
    IP = []
    file_handler = open(fileLocation, 'a+')
    for i in range(numOfLines):
        IP.append(generateIP()+"\n")
    file_handler.writelines(IP)
    file_handler.close()

if __name__ == '__main__':
    print time.ctime()
    for i in range(10):
        print "  " + str(i) + ": " + time.ctime()
        generateMassiveIPAddr('massiveIP.txt', 10000000)
    print time.ctime()
