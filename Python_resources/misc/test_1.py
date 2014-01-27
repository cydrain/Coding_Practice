def solution(A):
    N = len(A)
    min_array = [0] * N
    max_array = [0] * N

    max_value = A[0]
    for i in range(N):
        if (A[i] > max_value):
            max_value = A[i]
        max_array[i] = max_value
    print max_array

    min_value = A[N-1]
    i = N -1
    while (i >= 0):
        if (A[i] < min_value):
            min_value = A[i]
        min_array[i] = min_value
        i = i - 1
    print min_array

    result = -1
    for i in range(N):
        if (max_array[i] == min_array[i]):
            result = i
            break

    return result

A = [4,2,2,3,1,4,7,8,6,9]
print solution(A)
