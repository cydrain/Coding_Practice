# In the city, roads are arranged in a grid pattern. Each point on the grid
# represents a corner where two blocks meet. The points are connected by line
# segments which represent the various street blocks. Using the cartesian
# coordinate system, we can assign a pair of integers to each corner as shown
# below.
# You are standing at the corner with coordinates (0,0). Your destination is at
# corner (width,height). You will return the number of distinct paths that lead
# to your destination. Each path must use exactly width+height blocks.
# In addition, the city has declared certain street blocks untraversable. These
# blocks may not be a part of any path. You will be given a String[] bad
# describing which blocks are bad. If (quotes for clarity) "a b c d" is an
# element of bad, it means the block from corner (a,b) to corner (c,d) is
# untraversable. For example, let's say
# width  = 6
# length = 6
# bad = {"0 0 0 1","6 6 5 6"}
# The picture below shows the grid, with untraversable blocks darkened in black.
# A sample path has been highlighted in red.
def numWays(row, col, bad):
    dp  = [[0 for j in range(col+1)] for i in range(row+1)]
    obs = [[0 for j in range(col+1)] for i in range(row+1)]
    for i in range(len(bad)):
        A = bad[i].split()
        obs[int(A[0])][int(A[1])] = 1
        obs[int(A[2])][int(A[3])] = 1
    #print obs
    
    dp[row][col] = 1
    i = row-1
    while (i >= 0):
        if (obs[i][col] and obs[i+1][col]):
            dp[i][col] = 0
        else:
            dp[i][col] = dp[i+1][col]
        i = i - 1
        
    j = col-1
    while (j >= 0):
        if (obs[row][j] and obs[row][j+1]):
            dp[row][j] = 0
        else:
            dp[row][j] = dp[row][j+1]
        j = j - 1

    i = row - 1
    while (i >= 0):
        j = col - 1
        while (j >= 0):
            if (not (obs[i][j] and obs[i+1][j])):
                dp[i][j] += dp[i+1][j]
            if (not (obs[i][j] and obs[i][j+1])):
                dp[i][j] += dp[i][j+1]
            j = j - 1
        i = i - 1
        
    #print dp
    return dp[0][0]

print numWays(6, 6, ["0 0 0 1", "6 6 5 6"])
print numWays(35, 31, [])
