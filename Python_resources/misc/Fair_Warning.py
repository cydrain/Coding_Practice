import string

def gcd(a, b):
    if (a < b):
        return gcd(b, a)
    if (b == 0):
        return a
    else:
        return gcd(b, a%b)

# get the GCD among the whole array
def gcd_all(array):
    len_arr = len(array)
    temp = array[0]
    for i in range(1, len_arr):
        temp = gcd(temp, array[i])
    return temp
    
def handle_file(filename):
    fp_i = open(filename+".in", "r")
    fp_o = open(filename+".out", "w")

    line = fp_i.readline().split()
    C = string.atoi(line[0])

    for c in range(C):
        line = fp_i.readline().split()
        N = string.atoi(line.pop(0))
        line = [string.atol(line[j]) for j in range(N)]
        line2 = [0 for i in range(N-1)]
        # sort the array from big to small
        line.sort(None, None, True)

        # line2[] stores the diff value between immediate elements in line[]
        for i in range(N-1):
            line2[i] = line[i] - line[i+1]

        T = gcd_all(line2)

        if (line[0]%T):
            y = (line[0]/T+1)*T-line[0]
        else:
            y = 0
            
        result = "Case #%d: %ld\n"%(c+1, y)
        print result, T
        fp_o.write(result)
       
    fp_i.close()
    fp_o.close()

handle_file("B-small-practice")
handle_file("B-large-practice")

