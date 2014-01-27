import string

def solution(s):
    len_s = len(s)
    curr = s[0]
    count = 1
    for i in range(1, len_s):
        if (s[i] == curr):
            count = count + 1
        else:
            print "%c%d"%(curr,count),
            curr = s[i]
            count = 1
    print "%c%d"%(curr,count)

solution('123342225667')
        
