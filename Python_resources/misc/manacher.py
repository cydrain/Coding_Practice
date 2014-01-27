def palindrome_manacher(s):
    len_s = len(s)
    arr = [0] * (2*len_s+3)
    p = [1] * (2*len_s+3)

    arr[0] = '$'
    arr[1] = '#'
    for i in range(len_s):
        arr[2*i+2] = s[i]
        arr[2*i+3] = '#'
    arr[2*len_s+2] = '\0'

    idx = 0
    mx = 0

    for i in range(2, 2*len_s+2):
        if (i < mx):
            p[i] = min(p[2*idx-i], mx-i)
        else:
            p[i] = 1
        while (arr[i-p[i]] == arr[i+p[i]]):
            p[i] = p[i] + 1
        if (mx < i + p[i]):
            mx = i + p[i]
            idx = i

    print arr
    print p
    print idx, mx

s = "abaabcabca"
palindrome_manacher(s)
