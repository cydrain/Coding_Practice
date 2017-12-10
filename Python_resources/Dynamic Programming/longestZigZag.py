# A sequence of numbers is called a zig-zag sequence if the differences
# between successive numbers strictly alternate between positive and
# negative.
# The first difference (if one exists) may be either positive or negative.
# A sequence with fewer than two elements is trivially a zig-zag sequence.
#
# For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences
# (6,-3,5,-7,3) are alternately positive and negative.
# In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first
# because its first two differences are positive and the second because its
# last difference is zero.
#
# Given a sequence of integers, sequence, return the length of the longest
# subsequence of sequence that is a zig-zag sequence. A subsequence is
# obtained by deleting some number of elements (possibly zero) from the
# original sequence, leaving the remaining elements in their original order.


# let rise[i] to store the longest zigzig number for seq[0:i] with the first difference is positive
# let fall[i] to store the longest zigzig number for seq[0:i] with the first difference is negative
# rise[i] = max{rise[i], 1}         (0 <= j < i, rise[j] == 0 and rise[i] > rise[j])
#         = max{rise[i], rise[j]+1} (0 <= j < i, rise[j] is even and rise[i] > rise[j],
#                                             or rise[j] is odd  and rise[i] < rise[j])
# similar for fall[]
# the final result will be max(rise[n-1], fall[n-1])+1

def longestZigZag(seq):
    n = len(seq)
    if (n <= 2):
        return n

    rise = [0 for i in range(n)]
    fall = [0 for i in range(n)]

    # calculate the first difference is positive
    for i in range(n):
        for j in range(i):
            if (rise[j] == 0):
                if (seq[i] > seq[j]):
                    rise[i] = max(rise[i], 1)
            elif ((rise[j]%2 == 0 and seq[i] > seq[j]) or
                  (rise[j]%2 == 1 and seq[i] < seq[j])):
                rise[i] = max(rise[i], rise[j]+1)
            #print i, j, rise

    # calculate the first difference is negative
    for i in range(n):
        for j in range(i):
            if (fall[j] == 0):
                if (seq[i] < seq[j]):
                    fall[i] = max(fall[j], 1)
            elif ((fall[j]%2 == 0 and seq[i] < seq[j]) or
                  (fall[j]%2 == 1 and seq[i] > seq[j])):
                fall[i] = max(fall[i], fall[j]+1)
            #print i, j, fall
            
    return max(rise[n-1], fall[n-1])+1

A1 = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
A2 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
A3 = [70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32]
A4 = [374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244]
print longestZigZag(A4)
                        
