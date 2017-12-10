def quicksort(A, start, end):
    if (start >= end):
        return
    pivot = A[start]
    low = start
    high = end
    while (low < high):
        while (low < high and A[high] >= pivot):
            high -= 1
        A[low] = A[high]
        while (low < high and A[low] <= pivot):
            low += 1
        A[high] = A[low]
    A[low] = pivot
    quicksort(A, start, low-1)
    quicksort(A, low+1, end)

A = [1,4,9,3,4,1,5,2,8]
#A = [2,1,3]
quicksort(A, 0, len(A)-1)
print A
