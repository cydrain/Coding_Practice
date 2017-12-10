import string

def calc_money(R, k, N, group):
    money = 0
    start_idx = 0
    for i in range(R):
        curr_ride = 0
        curr_idx = start_idx
        while (True):
            if (curr_ride+group[curr_idx] <= k):
                curr_ride += group[curr_idx]
            else:
                break
            curr_idx += 1
            if (curr_idx >= N):
                curr_idx = 0
            if (curr_idx == start_idx):
                break
        #print i, start_idx, curr_idx, curr_ride
        start_idx = curr_idx
        money += curr_ride
    return money

def calc_next_idx(k, N, group, next_idx):
    for i in range(N):
        curr_ride = 0
        curr_idx = i
        while (True):
            if (curr_ride+group[curr_idx] <= k):
                curr_ride += group[curr_idx]
            else:
                break
            curr_idx += 1
            if (curr_idx >= N):
                curr_idx = 0
            if (curr_idx == i):
                break
        next_idx[i] = (curr_idx, curr_ride)
    #print "next_idx calc done!"
    #print group
    #print next_idx
    
def calc_money_fast(R, k, N, group):
    money = 0
    # next_idx[][0] hold the next start index
    # next_idx[][1] hold the rider num in the next run
    next_idx = [[0,0] for i in range(N)]
    # visited[][0] hold the No. of run
    # visited[][1] hold the money earned before current run
    # so when we meet visited[][] with valid value, loop detected
    # (i-visited[][0]) is the loop interval
    # (money-visited[][1]) is the money it can earn in one loop
    visited = [[-1,-1] for i in range(N)]
    calc_next_idx(k, N, group, next_idx)
    curr_idx = 0
    loop_detected = False
    i = 0
    while (i < R):
        #print "round", i
        if (visited[curr_idx][0] == -1 or loop_detected):
            if (not loop_detected):
                visited[curr_idx] = [i,money]
                #print "visited[%d]=[%d,%d]"%(curr_idx,i,money)
            #print "next_idx=%d, next_money=%d"%(next_idx[curr_idx][0], next_idx[curr_idx][1])
            money += next_idx[curr_idx][1]
            curr_idx = next_idx[curr_idx][0]

        else:
            loop_detected = True
            loop_interval = i - visited[curr_idx][0]
            loop_money = money - visited[curr_idx][1]
            loops = (R-i)/loop_interval
            #print "loop start:", visited[curr_idx][0]
            #print "loop end:", i
            #print "loop money:", loop_money
            #print "loops:", loops
            money += loops * loop_money
            i += loops * loop_interval
            continue
        i += 1
        
    return money

def handle_file(filename):
    fp_i = open(filename+".in", "r")
    fp_o = open(filename+".out", "w")

    line = fp_i.readline().split()
    T = string.atoi(line[0])
    #print "T =", T

    for i in range(T):
        line = fp_i.readline().split()
        line = [string.atol(line[j]) for j in range(3)]
        R = line[0]
        k = line[1]
        N = line[2]
        #print R, k, N
        
        group = fp_i.readline().split()
        group = [string.atoi(group[j]) for j in range(N)]
        #print group

        #result = "Case #%d: %ld\n"%(i+1, calc_money(R, k, N, group))
        result = "Case #%d: %ld\n"%(i+1, calc_money_fast(R, k, N, group))
        #print result
        fp_o.write(result)
        
    fp_i.close()
    fp_o.close()
    
handle_file("C-large-practice")
#print calc_money(4, 6, 4, [1, 4, 2, 1])
#print calc_money(100, 10, 1, [1])
#print calc_money(5, 5, 10, [2,4,2,3,4,2,1,2,1,3])
#print calc_money(20, 5, 10, [2,4,2,3,4,2,1,2,1,3])
#print calc_money_fast(20, 5, 10, [2,4,2,3,4,2,1,2,1,3])
#print calc_money_fast(100, 10, 1, [1])
