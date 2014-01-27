'''
Given a string s, partition s such that every substring of
the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
'''

def cal_palindrome(s, dp):
    len_s = len(s)
    for i in range(len_s):
        dp[i][i] = 1
    for i in range(len_s-1):
        if (s[i] == s[i+1]):
            dp[i][i+1] = 1
            
    for j in range(2, len_s):
        for i in range(len_s-j):
            if (s[i] == s[i+j] and dp[i+1][i+j-1]):
                dp[i][i+j] = 1
                #print i, i+j
'''
    for j in range(len_s):
        for i in range(len_s):
            print dp[i][j],
        print "\n"
'''

def partition(s, start, end, dp, par, subpar=[]):
    if (start == end):
        #print subpar
        par.append(subpar)
        return
    for i in range(start, end):
        if (dp[start][i]):
            #print start, i, s[start:i+1], subpar
            partition(s, i+1, end, dp, par, subpar+[s[start:i+1]])

def solution(s):
    len_s = len(s)
    dp = [[0 for col in range(len_s)] for row in range(len_s)]
    cal_palindrome(s, dp)
    par = []
    partition(s, 0, len_s, dp, par)           
    return par

par = solution("ababbac")
print par
