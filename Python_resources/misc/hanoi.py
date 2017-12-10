import sys
import string
import copy

# get the disk No. on the top of a peg
def top_disk(disk_num, peg_num, peg_no, state):
    for i in range(disk_num):
        if (state[i] == peg_no):
            return i
    
#def move(from_peg, to_peg, state):

init = []
finl = []
solution = []

fp = open("hanoi_01.txt", 'r')
lines = fp.readlines()
#print lines
disk_num,peg_num = [string.atoi(item) for item in string.split(lines[0])]
init.extend([string.atoi(item) for item in string.split(lines[1])])
finl.extend([string.atoi(item) for item in string.split(lines[2])])

print disk_num, peg_num
print init
print finl
fp.close()
