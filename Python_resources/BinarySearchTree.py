class Node:
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right
        
        
class BSTree:
    def __init__(self):
        self.root = None
        self.size = 0
        self.depth = 0

    def insert(self, node):
        if (self.root == None):
            self.root = node
            self.depth = 1
        else:
            curr = self.root
            depth = 1
            while (True):
                if (node.value == curr.value):
                    print "Node already exists in BSTree, insert fail."
                    return False
                elif (node.value < curr.value):
                    if (curr.left == None):
                        curr.left = node
                        self.depth = max(self.depth, depth+1)
                        break
                    else:
                        curr = curr.left
                        depth += 1
                else:
                    if (curr.right == None):
                        curr.right = node
                        self.depth = max(self.depth, depth+1)
                        break
                    else:
                        curr = curr.right
                        depth += 1
        self.size += 1
        return True

    def bfs(self, node):
        if (node == None):
            return
        queue = []
        queue.append(node)
        while (len(queue)):
            curr = queue.pop(0)
            print curr.value,
            if (curr.left):
                queue.append(curr.left)
            if (curr.right):
                queue.append(curr.right)

    # breath first search, print level by level
    def bfs_2(self, node):
        if (node == None):
            return
        level_record = []
        currQ = []
        nextQ = []
        currQ.append(node)
        while (len(currQ)):
            curr = currQ.pop(0)
            #print curr.value,
            level_record.append(curr.value)
            if (curr.left):
                nextQ.append(curr.left)
            if (curr.right):
                nextQ.append(curr.right)
            if (len(currQ) == 0):
                print level_record
                level_record = []
                currQ,nextQ = nextQ,currQ
                
    def preOrder(self, node):
        if (node is not None):
            print node.value,
            self.preOrder(node.left)
            self.preOrder(node.right)

    def inOrder(self, node):
        if (node is not None):
            self.inOrder(node.left)
            print node.value,
            self.inOrder(node.right)

    def postOrder(self, node):
        if (node is not None):
            self.postOrder(node.left)
            self.postOrder(node.right)
            print node.value,

    def BST2List(self, node, head=None):
        if (node is not None):
            #print "curr node", node.value
            head = self.BST2List(node.left, head)
            if (head is None):
                head = node
                head.left = node
            else:               
                node.left = head.left
                head.left = node
                node.left.right = node
            right = node.right
            node.right = head
            head = self.BST2List(right, head)
            #print "head", head.value, "head.left", head.left.value, "head.right", head.right.value
            return head
        else:
            return head

    def BST2List_2(self, node, head=None):
        if (node is not None):
            print "curr:", node.value
            left = node.left
            right = node.right
            if (head is None):
                head = node
                head.left = node
            else:
                node.left = head.left
                head.left = node
                node.left.right = node
            node.right = head
            print "head", head.value, "head.left", head.left.value, "head.right", head.right.value
            self.BST2List_2(left, head)
            self.BST2List_2(right, head)
        return head
        

tree = BSTree()
tree.insert(Node(6))
tree.insert(Node(3))
tree.insert(Node(4))
tree.insert(Node(9))
tree.insert(Node(8))
tree.insert(Node(7))
tree.insert(Node(2))

print "\n# tree depth:", tree.depth

print "\n# preOrder iteration: "
tree.preOrder(tree.root)

print "\n# inOrder iteration: "
tree.inOrder(tree.root)

print "\n# postOrder iteration: "
tree.postOrder(tree.root)

print "\n# Bread first iteration: "
tree.bfs(tree.root)

print "\n# Bread first iteration (level by level): "
tree.bfs_2(tree.root)
'''
print "\n# Convert BSTree to double link list: "
head = tree.BST2List(tree.root)
for i in range(tree.size+1):
    print head.value, head.left.value, head.right.value
    head = head.right
'''
print "\n# Convert BSTree to double link list 2: "
head = tree.BST2List_2(tree.root)
for i in range(tree.size+1):
    print head.value, head.left.value, head.right.value
    head = head.right
