def pascal_triangle(n):
    array = []
    for i in range(n):
        for j in range(i-1, 0, -1):
            array[j] = array[j-1] + array[j]
        array.append(1)
        print array

pascal_triangle(1)
pascal_triangle(2)
pascal_triangle(10)
            
