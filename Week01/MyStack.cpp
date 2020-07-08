class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        inQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(inQueue.size() > 1) {
            outQueue.push(inQueue.front());
            inQueue.pop();
        }
        int res = inQueue.front();
        inQueue.pop();
        while(outQueue.size() > 0) {
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = inQueue.back();
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(inQueue.empty() && outQueue.empty()) {
            return true;
        }
        return false;
    }

    queue<int> inQueue;
    queue<int> outQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */