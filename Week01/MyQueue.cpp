class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        checkEmpty();
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        checkEmpty();
        int res = outStack.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(inStack.empty() && outStack.empty()) {
            return true;
        }
        return false;
    }

    void checkEmpty() {
        if(outStack.size() == 0) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    stack<int> inStack;
    stack<int> outStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */