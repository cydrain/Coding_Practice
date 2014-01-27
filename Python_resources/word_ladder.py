maxint = 0xffff
def wordAdj(w1, w2):
    len_w = len(w1)
    diff = 0
    for i in range(len_w):
        if (w1[i] != w2[i]):
            if (diff == 0):
                diff += 1
            else:
                return False
    return (diff == 1)

def calcDictAdjTbl(dt, cost):
    len_dt = len(dt)
    #cost = [[maxint for col in range(len_dt)] for row in range(len_dt)]
    for i in range(len_dt):
        for j in range(i+1, len_dt):
            if (wordAdj(dt[i], dt[j])):
                cost[i][j] = cost[j][i] = 1
    #for i in range(len_dt):
    #    print cost[i]

def printPath(dt, path):
    for i in range(len(path)):
        print dt[path[i]],
    print ''
    
def getAllPath(dt, start_idx, end_idx, preNode, path=[], solution=[]):
    #print path
    if (start_idx == end_idx and len(path) > 1):
        solution.append(path)
        printPath(dt, path)
    else:
        #print end_idx, preNode[end_idx]
        for i in range(len(preNode[end_idx])):
            #print i, preNode[end_idx][i]
            getAllPath(dt, start_idx, preNode[end_idx][i], preNode, [preNode[end_idx][i]]+path, solution)
        
def ladderLength(start, end, dt):
    len_dt = len(dt)
    start_idx = dt.index(start)
    end_idx = dt.index(end)
    print start_idx, end_idx
    cost = [[maxint for col in range(len_dt)] for row in range(len_dt)]
    calcDictAdjTbl(dt, cost)
    preNode = [[] for i in range(len_dt)]
    dist = [cost[start_idx][i] for i in range(len_dt)]
    for i in range(len_dt):
        if (dist[i] == 1):
            preNode[i].append(start_idx)
    
    visited = set([start_idx])
    unvisited = set([i for i in range(len_dt)])
    unvisited.remove(start_idx)

    while (len(unvisited) > 1):
        minlen = maxint
        #print "dist:", dist
        #print "unvisited:", unvisited
        for i in unvisited:
            #print "i=",i
            if (minlen > dist[i]):
                minlen = dist[i]
                minidx = i
                #print "min:", i, dist[i]

        if (minlen == maxint):
            print "No such transformation sequence"
            return 0

        if (minidx == end_idx):
            print "Got the transformation sequence"
            break
        
        visited.add(minidx)
        unvisited.remove(minidx)

        for i in unvisited:
            if (dist[i] > dist[minidx] + cost[minidx][i]):
                dist[i] = dist[minidx] + cost[minidx][i]
                preNode[i] = [minidx]
                #print "dist[%d]=%d"%(i, dist[i])
            elif (dist[i] == dist[minidx] + cost[minidx][i]):
                preNode[i].append(minidx)

    #print preNode
    solution = []
    getAllPath(dt, start_idx, end_idx, preNode, [end_idx], solution)
    if (dist[end_idx] == maxint):
        return 0
    else:
        return dist[end_idx]+1;

start = "hot"
end = "dog"
dt = ["hot","cog","dog","tot","hog","hop","pot","dot"]
#start = "leet"
#end = "code"
#dt = ["lest","leet","lose","code","lode","robe","lost"]
#start = "kite"
#end = "ashy"
#dt = ["ante","does","jive","achy","kids","kits","cart","ache","ands","ashe","acne","aunt","aids","kite","ants","anne","ashy"]

print ladderLength(start, end, dt)
