import string

N = 9

def valid(vec):
    flag = [False for i in range(N)]
    for i in range(N):
        curr_char = vec[i]
        if (curr_char == '.'):
            continue
        curr_val = string.atoi(curr_char)
        if (flag[curr_val-1]):
            return False
        else:
            flag[curr_val-1] = True
    return True
            
def check_valid(board, x, y):
    vec = [0] * N
    #check row
    if (not valid(board[x])):
        return False

    #check col
    for i in range(N):
        vec[i] = board[i][y]
    if (not valid(vec)):
        return False

    #check block
    row_sta = x/3 * 3
    col_sta = y/3 * 3
    n = 0
    for i in range(row_sta, row_sta+3):
        for j in range(col_sta, col_sta+3):
            vec[n] = board[i][j]
            n = n + 1
    if (not valid(vec)):
        return False

    return True

    
def find_first_empty(board):
    for i in range(N):
        for j in range(N):
            if (board[i][j] == '.'):
                return (i, j)
    else:
        return (-1, -1)

def sudoku_print(board):
    for i in range(N):
        for j in range(N):
            print "%d  " % string.atoi(board[i][j]),
        print "\n"

def sudoku_solver(board, level=0):
    (x, y) = find_first_empty(board)
    if (x == -1 and y == -1):
        print "Solution found !\n"
        sudoku_print(board)
        return True

    #print level, x, y
    for val in range(1, N+1):        
        board[x][y] = '%d' % val
        if (check_valid(board, x, y) and
            sudoku_solver(board, level+1)):
            return True
        else:
            board[x][y] = '.'

    return False
    

board = [['.' for col in range(9)] for row in range(9)]
board[0] = "5 3 . . 7 . . . .".split()
board[1] = "6 . . 1 9 5 . . .".split()
board[2] = ". 9 8 . . . . 6 .".split()
board[3] = "8 . . . 6 . . . 3".split()
board[4] = "4 . . 8 . 3 . . 1".split()
board[5] = "7 . . . 2 . . . 6".split()
board[6] = ". 6 . . . . 2 8 .".split()
board[7] = ". . . 4 1 9 . . 5".split()
board[8] = ". . . . 8 . . 7 9".split()

sudoku_solver(board)

