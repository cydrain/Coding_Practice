def solution(A,B,C,D):
    maxint = 0xffff
    M = len(A)
    N = len(D)
    cost = {}
    for i in range(M):
        if ((not cost.has_key((A[i], B[i]))) or
            (cost.has_key((A[i], B[i])) and
             cost[(A[i], B[i])] > C[i])):
            cost[(A[i], B[i])] = C[i]
            cost[(B[i], A[i])] = C[i]
    print cost
            
    dist = [maxint] * N
    for i in range(N):
        if (cost.has_key((0, i))):
            dist[i] = cost[(0, i)]
    print dist

    visited = [0]
    while(1):
        min_dist = maxint
        next_idx = 0
        for (key,value) in cost.items():
            if (key[0] in visited and
                key[1] not in visited):
                if (min_dist > value):
                    min_dist = value
                    from_idx = key[0]
                    to_idx = key[1]
                    print 'next_idx =', next_idx
        if (min_dist == maxint):
            break

        visited.append(to_idx)
        #print 'visited =', visited
        cost.pop((from_idx, to_idx))
        cost.pop((to_idx, from_idx))

        for i in range(1, N):
            if (i not in visited and
                cost.has_key((to_idx, i))):
                if (dist[i] > dist[to_idx] + cost[(to_idx, i)]):
                    dist[i] = dist[to_idx] + cost[(to_idx, i)]
                    print 'i =', i, 'dist[i] =', dist[i]

        if (len(visited) == (N-1)):
            break

    min_solution = maxint
    for i in range(N):
        if (D[i] != -1 and dist[i] < D[i]):
            if (min_solution > dist[i]):
                min_solution = dist[i]

    if (min_solution == maxint):
        return -1
    else:
        return min_solution

#A = [0, 1, 3, 1, 2, 2]
#B = [1, 2, 2, 3, 0, 1]
#C = [2, 3, 4, 5, 7, 5]
#D = [-1, 1, 3, 8]
#A = [6, 6, 3, 8, 8, 6, 7, 5, 1, 4, 3, 2, 7, 7]
#B = [3, 7, 5, 8, 0, 6, 3, 4, 1, 7, 1, 5, 3, 2]
#C = [8, 1, 9, 12, 11, 1, 8, 12, 3, 6, 12, 7, 4, 2]
#D = [-1, 1000000000, 1000000000, 999999999, 999999999, 999999999, 1000000000, 1000000000, 1000000000]
A = [0, 2, 3, 1, 4, 1, 0, 2, 1]
B = [0, 3, 2, 4, 4, 3, 3, 2, 2]
C = [10, 2, 4, 7, 1, 9, 1, 3, 9]
D = [-1, 1000000000, 899, 0, 999999999]
#print A, B, C, D
print solution(A,B,C,D)
