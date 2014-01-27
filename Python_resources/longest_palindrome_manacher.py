def longest_palindrome_manacher(s):
    len_s = len(s)
    s1 = ['\0' for i in range(2*len_s+3)]
    p = [1 for i in range(2*len_s+3)]
    
    s1[0] = '$'
    s1[1] = '#'
    for i in range(len_s):
        s1[2*i+2] = s[i]
        s1[2*i+3] = '#'

    idx = 1
    mx = 1

    for i in range(1, 2*len_s+2):
        if (mx > i):
            p[i] = min(p[2*idx-i], mx-i)
        else:
            p[i] = 1

        while (s1[i-p[i]] == s1[i+p[i]]):
            p[i] = p[i] + 1

        if (mx < i + p[i]):
            mx = i + p[i]
            idx = i

    max_idx = 1
    max_len = 1
    for i in range(2*len_s+3):
        if (max_len < p[i]):
            max_len = p[i]
            max_idx = i
            
    print s
    print s1
    print p
    print max_idx, max_len
    print s[(max_idx-max_len)/2:(max_idx+max_len-2)/2]

longest_palindrome_manacher("abcbababcbdab")
