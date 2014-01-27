# Suppose you had an n by n chess board and a super piece called a kingknight.
# Using only one move the kingknight denoted 'K' below can reach any of the
# spaces denoted 'X' or 'L' below:
#
#   .......
#   ..L.L..
#   .LXXXL.
#   ..XKX..
#   .LXXXL.
#   ..L.L..
#   .......
#
# In other words, the kingknight can move either one space in any direction
# (vertical, horizontal or diagonally) or can make an 'L' shaped move. An 'L'
# shaped move involves moving 2 spaces horizontally then 1 space vertically
# or 2 spaces vertically then 1 space horizontally. In the drawing above, the
# 'L' shaped moves are marked with 'L's whereas the one space moves are marked
# with 'X's. In addition, a kingknight may never jump off the board.
#
# Given the size of the board, the start position of the kingknight and the
# end position of the kingknight, your method will return how many possible
# ways there are of getting from start to end in exactly numMoves moves.
# start and finish are int[]s each containing 2 elements. The first element
# will be the (0-based) row position and the second will be the (0-based)
# column position. Rows and columns will increment down and to the right
# respectively. The board itself will have rows and columns ranging from 0
# to size-1 inclusive.
#
# Note, two ways of getting from start to end are distinct if their respective
# move sequences differ in any way. In addition, you are allowed to use spaces
# on the board (including start and finish) repeatedly during a particular path
# from start to finish. We will ensure that the total number of paths is less
# than or equal to 2^63-1 (the upper bound for a long).
def calcNumSteps(size, x, y, board):
    offset = [[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1],[-1,0],[-1,1],
              [1,2],[2,1],[2,-1],[1,-2],[-1,-2],[-2,-1],[-2,1],[-1,2]]
    num = 0
    for i in range(len(offset)):
        idx_x = x + offset[i][0]
        idx_y = y + offset[i][1]
        if (idx_x < 0 or idx_x >= size or
            idx_y < 0 or idx_y >= size):
            continue
        num += board[idx_x][idx_y]
    return num
    
def ChessMetric(size, start, end, numMoves):
    dp = [[[0 for i in range(size)] for j in range(size)] for k in range(numMoves+1)]
    dp[0][start[0]][start[1]] = 1
    for step in range(1, numMoves+1):
        for x in range(size):
            for y in range(size):
                dp[step][x][y] = calcNumSteps(size, x, y, dp[step-1])
        #print dp[step]
    return dp[numMoves][end[0]][end[1]]
    
print ChessMetric(3, [0,0], [0,0], 2)
print ChessMetric(100, [0,0], [0,99], 50)
