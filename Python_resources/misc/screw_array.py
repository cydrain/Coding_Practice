def screw_array(n):
    dir = [(1,0), (0,1), (-1,0), (0,-1)]
    array = [[0 for col in range(n)] for row in range(n)]
    curr_x = curr_y = 0
    curr_dir = 0
    num = 1

    while (True):
        if (array[curr_x][curr_y] == 0):
            array[curr_x][curr_y] = num
            #print "array[%d][%d] = %d" % (curr_x, curr_y, num)
            num = num + 1
        else:
            break
        
        next_x = curr_x + dir[curr_dir][0]
        next_y = curr_y + dir[curr_dir][1]
        if (next_x not in range(n) or
            next_y not in range(n) or
            array[next_x][next_y] != 0):
            curr_dir = (curr_dir+1)%len(dir)
            next_x = curr_x + dir[curr_dir][0]
            next_y = curr_y + dir[curr_dir][1]

        curr_x = next_x
        curr_y = next_y

    for j in range(n):
        for i in range(n):
            print "%2d " % array[i][j],
        print "\n"

screw_array(9)
