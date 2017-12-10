__author__ = "Cai Yudong (cydrain@gmail.com)"
__data__ = "$Date: 2013/09/24 $"

import os
import time

def findIP(targetDir):
    IP = {}
    result = {}
    for root, dirs, files in os.walk(targetDir):
        for f in files:
            print '  File ' + str(f) + ":"
            # read small file
            file_handler = open(os.path.join(targetDir, f), 'r')
            lines = file_handler.readlines()
            file_handler.close()
            # get IP in file, store to IP Directory
            for line in lines:
                if line in IP:
                    IP[line] = IP[line] + 1
                else:
                    IP[line] = 1
            # sort Directory
            IP = sorted(IP.items(), key=lambda d:d[1], reverse=True)
            # store the maximum 10 to Result Directory
            for i in range(10):
                result[IP[i][0]] = IP[i][1]
                print "    maxItem " + str(i) + " : " + str(IP[i])
            IP = {}
            print "    Finished: " + time.ctime()

    print "Finally result: "
    result = sorted(result.items(), key=lambda d:d[1], reverse=True)
    for i in range(10):
        print "  maxItem " + str(i) + " : " + str(result[i])
        
if __name__ == '__main__':
    print "Start: " + time.ctime()
    findIP("massiveData")
    print "End: " + time.ctime()

