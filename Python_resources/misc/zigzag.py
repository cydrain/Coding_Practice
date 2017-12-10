def zigzag(n):
    num = 0
    array = [[0 for col in range(n)] for row in range(n)]
    for k in range(2*n-1):
        if (k % 2 == 0):
            i = 0
            j = k - i
            if (j > n-1):
                j = n - 1
                i = k - j
            while (0 <= i <= n-1 and 0 <= j <= n-1):
                array[i][j] = num
                num = num + 1
                i = i + 1
                j = j - 1
        else:
            j = 0
            i = k - j
            if (i > n-1):
                i = n - 1
                j = k - i
            while (0 <= i <= n-1 and 0 <= j <= n-1):
                array[i][j] = num
                num = num + 1
                i = i - 1
                j = j + 1

    for j in range(n):
        for i in range(n):
            print "%2d " % array[i][j],
        print "\n"

zigzag(10)
                
