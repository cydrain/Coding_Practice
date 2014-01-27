def longest_palindrome(s):
    len_s = len(s)
    dp = [[0 for col in range(len_s)] for row in range(len_s)]

    dp_max = 0
    for j in range(len_s):
        for i in range(j+1):
            if (s[i] == s[j]):
                if ((j-i) < 2):
                    dp[i][j] = j - i + 1
                elif (dp[i+1][j-1]):
                    dp[i][j] = dp[i+1][j-1] + 2
                
                if (dp[i][j] > dp_max):
                    dp_max = dp[i][j]
                    dp_i = i
                    dp_j = j
                    #print i, j, dp_max
            else:
                dp[i][j] = 0

    print "The longest palindrome string is: ", s[dp_i:dp_j+1]
'''
    for i in range(len_s):
        print s[i],
    print "\n"
    for j in range(len_s):
        for i in range(len_s):
            if (dp[i][j] != -1):
                print dp[i][j],
            else:
                break
        print "\n"
'''
longest_palindrome("abadabadabbad")
