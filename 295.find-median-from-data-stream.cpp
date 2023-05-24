/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start

// follow-up reference: https://leetcode.com/problems/find-median-from-data-stream/discuss/2294998/Implementation-for-follow-ups
// follow-up reference: https://leetcode.com/problems/find-median-from-data-stream/discuss/354195/C%2B%2B-112-ms-99-solution-w-follow-up
class MaxHeap {
public: 
    vector<int> arr;

    MaxHeap() {}

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void shiftDown(int i) {
        int top = i;
        int size = arr.size() - 1;
        
        int l = left(i);
        if (l <= size && arr[l] > arr[top]) {
            top = l;
        }

        int r = right(i);
        if (r <= size && arr[r] > arr[top]) {
            top = r;
        }

        if (top != i) {
            swap(arr[top], arr[i]);
            shiftDown(top);
        }
    }

    void shiftUp(int i) {
        while (0 < i && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void push(int val) {
        arr.push_back(val);
        shiftUp(arr.size() - 1);
    }

    void pop() {
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        shiftDown(0);
    }

    int top() {
        return arr[0];
    }

    int size() {
        return arr.size();
    }
};

class MedianFinder {
public:
    MaxHeap large;
    MaxHeap small;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-(small.top())); small.pop();

        if (small.size() < large.size()) {
            small.push(-large.top()); large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

