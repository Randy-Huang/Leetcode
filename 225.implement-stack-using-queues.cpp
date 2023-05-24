/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

// Reference 1: https://leetcode.com/problems/implement-stack-using-queues/solutions/127844/implement-stack-using-queues/
// Reference 2: https://www.cnblogs.com/grandyang/p/4568796.html


// Solution 1: Use 2 queues
// class MyStack {
// public:
//     queue<int> normalQueue;
//     queue<int> topQueue;

//     MyStack() {
        
//     }
    
//     // Erevery time we push new element to top queue,
//     // but if it's size > 1, then pop up element from queue (it should be front element)
//     // and then push to normal queue (should be the last one)
//     // Time: O(1) because the top queue element won't be over 3 elements, max will be 2
//     void push(int x) {
//         topQueue.push(x);
//         while (topQueue.size() > 1) {
//             normalQueue.push(topQueue.front()); topQueue.pop();
//         }
//     }
    
//     // Time: O(1)
//     int pop() {
//         int res = top(); topQueue.pop();
//         return res;
//     }
    
//     // Time: O(N)
//     int top() {
//         if (topQueue.empty()) {
//             // Shift operation to get the first item in statck (it is in rear position in queue)
//             // after poping it, the front element in normal queue is still the same previous value
//             for (int i = 0; i < normalQueue.size() - 1; i++) {
//                 normalQueue.push(normalQueue.front()); normalQueue.pop();
//             }
//             topQueue.push(normalQueue.front()); normalQueue.pop();
//         }

//         return topQueue.front();
//     }
    
//     // Time: O(1)
//     bool empty() {
//         return topQueue.empty() && normalQueue.empty();
//     }
// };

// Solution 2: use one queue
class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    // We know the access sequentiences between queue and stack 
    // are quite different, they're opposite.
    // but if every time we push new elemnt in the queue 
    // and shit elements (size() - 1) so that we can let
    // the first element in the front position for the stack
    // example: [1, 3, 9, 6, 8]
    // queue steps:
    // step1: 1
    // step2: 1, 3 -> 3, 1
    // step3: 3, 1, 9 -> 9, 3, 1
    // step4: 9, 3, 1, 6 - > 6, 9, 3, 1
    // step5: 6, 9, 3, 1, 8 -> 8, 6, 9, 3, 1
    // Time: O(N)
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {
            que.push(que.front()); que.pop();
        }
    }
    
    int pop() {
        int res = que.front(); que.pop();
        return res;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

