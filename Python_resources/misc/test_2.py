import math

def calc(A):
    result = 0
    for i in range(len(A)):
        result = result + ((-2) ** i) * A[i]
    return result

def get_power_index(n):
    if (n > 0):
        result = 1
        total = result
        i = 0
        while (1):
            if (total >= n):
                break
            result = result * 4
            total = total + result
            i = i + 2
        return i
    if (n < 0):
        result = -2
        total = result
        i = 1
        while (1):
            if (total <= n):
                break
            result = result * 4
            total = total + result
            i = i + 2
        return i

def solution_1(A, B):
    result = []
    N = calc(A) + calc(B)
    if (N == 0):
        return result

    index = []
    while (N != 0):
        i = get_power_index(N)
        tmp = (-2) ** i
        #print i, tmp
        N = N - tmp
        index.append(i)
        #print index 

    result = [0] * (index[0]+1)
    for i in index:
        result[i] = 1

    return result

# better solution, O(M+N) 
def solution_2(A, B):
    len_A = len(A)
    len_B = len(B)
    max_len = max(len_A, len_B)
    if (len_A < max_len):
        A.extend([0]*(max_len - len_A))
    elif (len_B < max_len):
        B.extend([0]*(max_len - len_B))
        
    result = [0] * (max_len + 2)
    for i in range(max_len):
        result[i] = A[i] + B[i]
    #print result

    for i in range(max_len):
        while (1):
            if (result[i] >= 2):
                if (result[i+1] >= 1):
                    result[i] = result[i] - 2
                    result[i+1] = result[i+1] - 1
                else:
                    result[i] = result[i] - 2
                    result[i+1] = result[i+1] + 1
                    result[i+2] = result[i+2] + 1
            else:
                i = i + 1
                break

    #print result
    while (result[-1] == 0):
        result.pop(-1)
        
    return result
            
    
#A = [0,1,1,0,0,1,0,1,1,1,0,1,0,1,1]
#B = [0,0,1,0,0,1,1,1,1,1,0,1]

A = [1,1,1,1,1]
B = [1,1,1,1,1]
a1 = solution_1(A, B)
print calc(a1), '=', a1
a2 = solution_2(A, B)
print calc(a2), '=', a2
