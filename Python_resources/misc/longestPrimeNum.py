import math

def isPrime(x):
    n = int(math.sqrt(x))
    for i in range(2, n+1):
        if (x % i == 0):
            return False
    return True

def getAllPrime(array):
    for i in range(101, 1000):
        if (isPrime(i)):
            print len(array), i
            array.append(i)

def buildConnGraph(array, graph):
    n = len(array)
    for i in range(n):
        p = []
        for j in range(10):
            x = array[i] % 100 * 10 + j
            if (x in array):
                idx = array.index(x)
                p.append(idx)
                #print array[i], "->", array[idx]
        graph.append(p)

def calcDist(graph, dist, prev):
    n = len(graph)
    #for times in range(n):
    for i in range(n):
        for j in range(len(graph[i])):
            if (dist[graph[i][j]] < dist[i]+1):
                dist[graph[i][j]] = dist[i]+1
                prev[graph[i][j]] = i

def printPath(array, dist, prev):
    n = len(dist)
    for i in range(n):
        if (dist[i] > 0):
            A = []
            print "\n%d(%d):"%(i,dist[i]),
            p = i
            while (p != -1 and array[p] not in A):
                print array[p], "<-",
                A.append(array[p])
                p = prev[p]
                
prime_array = []
getAllPrime(prime_array)
#print prime_array
n = len(prime_array)
conn = []
buildConnGraph(prime_array, conn)
print conn
dist = [0] * n
prev = [-1] * n
calcDist(conn, dist, prev)
#print dist
#print prev
printPath(prime_array, dist, prev)
