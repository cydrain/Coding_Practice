/*
 * Min Stack
DescriptionHintsSubmissionsDiscussSolution

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */ 

class MinStack {
private:
    stack<int> s;
    stack<int> ms;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (ms.empty() || x <= ms.top()) ms.push(x);
    }
    
    void pop() {
        if (s.top() == ms.top()) ms.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
