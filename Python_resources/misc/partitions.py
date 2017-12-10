# dp[i][j] = 1 (if s[i:j+1] is palindrome)

def showPartitions(s, dp, start, end, curr=[], result=[]):
    if (start >= end):
        print curr
        result.append(curr)
        return
    for i in range(start, end):
        if (dp[start][i]):
            #print start, i, s[start:i+1]
            showPartitions(s, dp, i+1, end, curr+[s[start:i+1]], result)
            
def partitions(s):
    len_s = len(s)
    dp = [[0 for col in range(len_s)] for row in range(len_s)]
    for j in range(len_s):
        for i in range(j+1):
            #print i, j
            if ((s[i] == s[j]) and (((j-i)<2) or dp[i+1][j-1])):
                dp[i][j] = 1
                #print i,j
    for i in range(len_s):
        for j in range(len_s):
            print dp[i][j],
        print ''
    result = []
    showPartitions(s, dp, 0, len_s, [], result)

def minCut(s):
    len_s = len(s)
    dp = [[0 for col in range(len_s)] for row in range(len_s)]
    cut = [len_s for col in range(len_s+1)]
    cut[len_s] = 0
    for i in range(len_s-1, -1, -1):
        for j in range(len_s-1, i-1, -1):
            if ((s[i] == s[j]) and (((j-i)<2) or dp[i+1][j-1])):
                dp[i][j] = 1
                cut[i] = min(cut[i], cut[j+1]+1)
        print cut
    return cut[0]-1

s = "adbdcabacbab"
#partitions(s)
print minCut(s)
    
                
