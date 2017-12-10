import math
import string

def solution(i, j):
    abs_i = abs(i)
    abs_j = abs(j)
    n = max(abs_i, abs_j)
    if (abs_i > abs_j):
        if (i > 0):
            result = pow((2*n-1),2) + n + j
        else:
            result = pow((2*n-1),2) + 5*n - j
    else:
        if (j > 0):
            result = pow((2*n-1),2) + 3*n - i
        else:
            result = pow((2*n-1),2) + 7*n + i
    return result

while(True):
    i = input("Please input the coordinates i: ")
    j = input("Please input the coordinates j: ")
    if (i > 100):
        break
    print "i=",i,"j=",j
    print solution(i,j)
    
