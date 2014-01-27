def solution(A, B, C, D):
    maxint = 0xffff
    N = len(D)
    M = len(A)
    cost = [[maxint for col in range(N)] for row in range(N)]
    for i in range(M):
        if (C[i] < cost[A[i]][B[i]]):
            cost[A[i]][B[i]] = cost[B[i]][A[i]] = C[i]
    for i in range(N):
        cost[i][i] = 0
    dist = [0] * N
    for i in range(N):
        dist[i] = cost[0][i]
    #print cost
    #print dist

    visited = [0]
    unvisited = [i for i in range(1, N)]

    while (True):
        minvalue = maxint
        for i in unvisited:
            if (minvalue > dist[i]):
                minvalue = dist[i]
                next_idx = i
        if (minvalue == maxint):
            print "Un-reachable square", unvisited
            break

        visited.append(next_idx)
        unvisited.remove(next_idx)

        for i in unvisited:
            if (dist[i] > dist[next_idx] + cost[next_idx][i]):
                dist[i] = dist[next_idx] + cost[next_idx][i]

        if (len(unvisited) == 1):
            break

    minvalue = maxint
    for i in range(1, N):
        if (dist[i] <= D[i] and D[i] != -1):
            if (minvalue > dist[i]):
                minvalue = dist[i]

    if (minvalue == maxint):
        return -1
    else:
        return minvalue

A = [0,1,3,1,2,2]
B = [1,2,2,3,0,1]
C = [2,3,4,5,7,5]
D = [-1,1,3,8]
print solution(A,B,C,D)
