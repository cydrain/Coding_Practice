import math

def bit_rev(A):
    B = 0
    while (not (A&0x1)):
        A = A >> 1

    while (A):
        B = B << 1
        if (A & 0x1):
            B = B | 0x1
        A = A >> 1

    return B

def solution(A):
    A_sqrt = int(math.sqrt(A))
    minint = 0x7fffffff
    for i in range(1, A_sqrt+1):
        if (A % i == 0):
            j = A / i
            if (bit_rev(j) == i):
                if (j < minint):
                    minint = j
                if (bit_rev(i) == j):
                    if (i < minint):
                        minint = i
    if (minint == 0x7fffffff):
        return -1
    else:
        return minint

print solution(3245)
#print 59*bit_rev(59)
#print 55*bit_rev(55)
