class MyCircularDeque {

private:
int capacity;
int* arr;
int front;
int rear;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1;
        arr = new int[capacity];
         // 头部指向第 1 个存放元素的位置
        // 插入时，先减，再赋值
        // 删除时，索引 +1（注意取模）
        front = 0;
        // 尾部指向下一个插入元素的位置
        // 插入时，先赋值，再加
        // 删除时，索引 -1（注意取模）
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        else {
            front = (front - 1 + capacity) % capacity;
            arr[front] = value;          
            return true;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        else {
            arr[rear] = value;
            rear = (rear + 1) % capacity;
            return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        else {
            front = (front + 1) % capacity;
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        else {
            rear = (rear - 1 + capacity) % capacity;
            return true; 
        }
        if (isEmpty()) {
            return false;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[(rear - 1 + capacity ) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (front == rear) {
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if ((rear + 1) % capacity == front) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */