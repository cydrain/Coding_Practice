def findIndex(str1, str2, start, end, curr, path, result):
    if (curr == len(str2)):
        result.append(path)
        print result
        return
    for i in range(start, end):
        if (str1[i] == str2[curr]):
            print i, path
            findIndex(str1, str2, i+1, end, curr+1, path+[i], result)
        
def numDistinct(S, T):
    f = [0] * (len(T)+1);
    f[len(T)] = 1;
    for i in range(len(S)-1, -1, -1):
        for j in range(len(T)):
            f[j] += (S[i]==T[j])*f[j+1];
        print S[i], f
    return f[0];

def solution(s, t):
    result = []
    findIndex(s, t, 0, len(s), 0, [], result)
    print result

s = "abceabdcb"
t = "abc"
#solution(s, t)
numDistinct(s, t)    
