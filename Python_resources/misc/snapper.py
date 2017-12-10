import string

fp = open("A-large-practice.in", 'r')
fp_o = open("result_large.txt", 'w')

first_line = fp.readline().split()
T = string.atoi(first_line[0])
print T

for i in range(T):
    line = fp.readline().split()
    n = string.atoi(line[0])
    k = string.atoi(line[1])
    #print n, k
    if ((((1<<n)-1)&k) == ((1<<n)-1)):
    #if (((1 << (n-1)) ^ (k & ((1 << n)-1))) == ((1 << (n-1))-1)):
        result_str = "Case #%d: ON\n"%(i+1)
    else:
        result_str = "Case #%d: OFF\n"%(i+1)
    #print result_str
    fp_o.write(result_str)

fp.close()
fp_o.close()
