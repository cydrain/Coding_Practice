# f(i,j) 
def minDistinct(s, t):
    len_s = len(s)
    len_t = len(t)
    dp = [0 for i in range(len_t+1)]
    dp[len_t] = 1
    for i in range(len_s-1, -1, -1):
        for j in range(len_t):
            if (s[i] == t[j]):
                dp[j] += dp[j+1]
        print s[i], dp
    return dp[0]

s = 'aa'
t = 'aaa'
print minDistinct(s, t)
