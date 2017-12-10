def count_1(n):
    count = 0
    exp = 1
    while (exp <= n):
        low = n % exp
        curr = (n / exp) % 10
        hi = (n / exp) / 10
        #print hi, curr, low
        if (curr == 0):
            tmp = hi*exp
        elif (curr == 1):
            tmp = hi*exp + (low+1)
        else:
            tmp = (hi+1)*exp
        #print tmp
        count = count + tmp
        exp = exp * 10
    return count

while (True):
    n = input("Please input the number: ")
    if (n < 0):
        break
    print count_1(n)
