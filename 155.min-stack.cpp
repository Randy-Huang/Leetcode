/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
private: 
    stack<long> st;
    long minVal = 0;

public:

    MinStack() {
        
    }
    
    void push(int val) {
        // we can use offset = real value - min to implement min value memorization
        // last_min_offset = stack.push(realValue - min);
        // and we have "realValue = last_min_offset + min"
        if (st.empty()) {
            st.push(0);
            minVal = val;
        } else {
            st.push(val - minVal); // push offset value to stack
            minVal = min((long)val, minVal);
        }
    }
    
    void pop() {
        long offset = st.top(); st.pop();
        if (offset < 0) { 
            // it means we popped the min value from the stack
            // we need to update the min value by offset
            minVal = minVal - offset;
        }
    }
    
    int top() {
        long offset = st.top();
        if (offset < 0) {
            return (int)minVal;
        } else {
            return (int)(offset + minVal);
        }
    }
    
    int getMin() {
        return (int) minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

