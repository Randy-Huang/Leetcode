/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
private:
    int INVALID = -1;

    vector<int> data;
    int capacity;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (++rear) % capacity;
        data[rear] = value;
        printf("rear: %d\n", rear);
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return INVALID;
        }

        return front;
    }
    
    int Rear() {
        if (isEmpty()) {
            return INVALID;
        }

        return rear;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
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
// @lc code=end

