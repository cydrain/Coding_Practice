'''
Given a string s, partition s such that every substring of the
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be
produced using 1 cut.
'''

# state transform formula:
# dp[i] = min{dp[i], dp[j+1]+1} (s(i,j) is palindrome && i<=j<=n)

def mincut(s):
    len_s = len(s)
    palin = [[0 for col in range(len_s)] for row in range(len_s)]
    dp = [(len_s-i) for i in range(len_s+1)]
    rt = [i for i in range(len_s)]
    #print dp
    
    for i in range(len_s-1, -1, -1):
        for j in range(i, len_s):
            if (s[i] == s[j] and ((j-i)<2 or palin[i+1][j-1])):
                palin[i][j] = 1
                if (dp[i] > dp[j+1]+1):
                    dp[i] = dp[j+1]+1
                    rt[i] = j

    #print rt
    i = 0
    while (i < len_s):
        print s[i:rt[i]+1],
        i = rt[i]+1
    print "\n"
    return dp[0]-1

#s = "abcbcaacb"                      
s = "11115100z"
print mincut(s)

