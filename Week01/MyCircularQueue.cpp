class MyCircularQueue {
    
public:
    int* data;
    int head;
    int tail;
    int size;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k + 1];
        head = 0;
        tail = 0; 
        size = k + 1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) {
            return -1;
        } 
        return data[head]; 
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return data[(tail - 1 + size) % size ];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;   
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail+1) % size == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */