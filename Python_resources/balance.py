import string
import math

class balance:
    def __init__(self, index, is_balanced = False, weight=10, left_weight=0, left_balance=[], right_weight=0, right_balance=[]):
        self.index = index
        self.weight = weight
        self.is_balanced = is_balanced
        self.left_weight = left_weight
        self.left_balance = left_balance
        self.right_weight = right_weight
        self.right_balance = right_balance

def adjust_balance(node, solution):
    if (node.is_balanced):
        return node.left_weight + node.right_weight + node.weight
    total_left = node.left_weight
    total_right = node.right_weight
    for i in range(0, len(node.left_balance)):
        total_left += adjust_balance(tree_array[node.left_balance[i]], solution)
    for i in range(0, len(node.right_balance)):
        total_right += adjust_balance(tree_array[node.right_balance[i]], solution)
    diff = total_left - total_right
    solution[node.index] = diff
    print "index", node.index, ":", total_left, total_right, diff
    node.is_balanced = True
    if (diff == 0):
        return (total_left + total_right + node.weight)
    elif (diff > 0):
        node.right_weight += diff
        return (total_left*2 + node.weight)
    else:
        node.left_weight -= diff
        return (total_right*2 + node.weight)
        
def adjust_balance_all(tree_array, solution):
    for i in range(0, len(tree_array)):
        #if (~tree_array[i].is_balanced):
        adjust_balance(tree_array[i], solution)
        
def show(balance):
    print balance.index, balance.weight, balance.is_balanced, balance.left_weight,
    print balance.left_balance, balance.right_weight, balance.right_balance

def str2int(array):
    for i in range(0, len(array)):
        array[i] = int(array[i])

def show_solution(solution):
    for i in range(0, len(solution)):
        if (solution[i] == 0):
            print i, ": 0 0"
        elif (solution[i] > 0):
            print i, ": 0", solution[i]
        else:
            print i, ":", abs(solution[i]), 0
        
        
# get input data
#tree_array = []
line_left = ''
line_right = ''
array_left = []
array_right = []

test_num = input()
tree_array = [None]*test_num
solution = [0]*test_num

for i in range(0, test_num):
    array_left = raw_input().split()
    array_right = raw_input().split()
    print "left balance:", array_left
    print "right balance:", array_right
    str2int(array_left)
    str2int(array_right)
    left_weight = array_left[0]
    del array_left[0]
    right_weight = array_right[0]
    del array_right[0]
    print "left balance:", left_weight, array_left
    print "right balance:", right_weight, array_right
    
    node = balance(i, False, 10, left_weight, array_left, right_weight, array_right)
    tree_array[i] = node

for i in range(0, test_num):
    show(tree_array[i])

adjust_balance_all(tree_array, solution)
#adjust_balance(tree_array[0], solution)
show_solution(solution)

for i in range(0, test_num):
    show(tree_array[i])

