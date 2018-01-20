/*
 * Implement Queue using Stacks
 *
 * Implement the following operations of a queue using stacks.
 *
 *   push(x) -- Push element x to the back of queue.
 *   pop() -- Removes the element from in front of queue.
 *   peek() -- Get the front element.
 *   empty() -- Return whether the queue is empty.
 */
class MyQueue {
private:
    stack<int> input, output;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = peek();
        output.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        int n;
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (input.empty() && output.empty());
    }
};
