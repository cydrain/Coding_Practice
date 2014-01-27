# Longest Common Subsequence
# let f(i,j) be the LCS for s[0:i] and t[0:j]
# then the transformation formula is:
# f(i,j) = f(i-1,j-1) + 1           (s[i] == t[j])
# f(i,j) = max(f(i-1,j), f(i,j-1))  (s[i] != t[j])

def showLCS(bt, s, i, j):
    if (i < 0 or j < 0):
        return
    if (bt[i][j] == 0):
        showLCS(bt, s, i-1, j-1)
        print s[i],
    elif (bt[i][j] == 1):
        showLCS(bt, s, i-1, j)
    else:
        showLCS(bt, s, i, j-1)
            
def LCS(s, t):
    len_s = len(s)
    len_t = len(t)
    dp = [[0 for col in range(len_t+1)] for row in range(len_s+1)]
    bt = [[0 for col in range(len_t)] for row in range(len_s)]
    for i in range(len_s):
        for j in range(len_t):
            if (s[i] == t[j]):
                dp[i+1][j+1] = dp[i][j] + 1
                bt[i][j] = 0
            else:
                if (dp[i][j+1] > dp[i+1][j]):
                    dp[i+1][j+1] = dp[i][j+1]
                    bt[i][j] = 1
                else:
                    dp[i+1][j+1] = dp[i+1][j]
                    bt[i][j] = -1
        #print dp[i]
        #print bt[i]
    showLCS(bt, s, len_s-1, len_t-1)
    return dp[len_s][len_t]

s = "abedacegbcbad"
t = "bcgedcbdaefg"
print LCS(s, t)
