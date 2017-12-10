import string

def f(m, n):
    array = [[1 for col in range(m+1)] for row in range(n+1)]
    array[0][1] = 0
    
    for i in range(1, m+1):
        for j in range(1, n+1):
            array[i][j] = array[i-1][j] + array[i][j-1]

    for i in range(m+1):
        print array[i]

f(10,10)
    
