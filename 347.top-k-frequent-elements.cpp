/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class MaxHeap {
public:
    int heapSize = -1;  
    
    vector<pair<int, int>> array;
    unordered_map<int, int> indices;

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

        int l = left(i);
        if (l <= heapSize && array[l].first > array[top].first) {
            top = l;
        }

        int r = right(i);
        if (r <= heapSize && array[r].first > array[top].first) {
            top = r;
        }

        if (top != i) {
            indices[array[top].second] = i;
            indices[array[i].second] = top;
            swap(array[top], array[i]);
            shiftDown(top);
        }
    }

    void shiftUp(int i) {
        while (i > 0 && array[i].first > array[parent(i)].first) {
            indices[array[i].second] = parent(i);
            indices[array[parent(i)].second] = i;
            swapData(array[i], array[parent(i)]);
            i = parent(i);
        }
    }

    void swapData(pair<int, int>& a, pair<int, int>& b) {
        pair<int, int> temp = a;
        a = b;
        b = temp;
    }

    void insert(int num) {
        if (indices.count(num)) {
            int index = indices[num];
            array[index].first++;
            shiftUp(index);
            return;
        }

        // for heap
        heapSize++;
        array.push_back(make_pair(1, num)); // (count, num)

        // for querying the counts for a num
        indices.insert({num, heapSize}); // {num, index}

        // update heap
        shiftUp(heapSize);
    }

    int getMax() {
        pair<int, int> res = array[0];

        array[0] = array[heapSize];
        heapSize--;

        shiftDown(0);
        indices.erase(res.second);

        return res.second;
    }

    void print() {
        printf("dump: [");
        for (int i = 0; i < array.size(); i++) {
            printf("{count: %d, num: %d},", array[i].first, array[i].second);
        }
        printf("]\n");
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        MaxHeap heap;
        for (auto num : nums) {
            heap.insert(num);
        }

        vector<int> res;
        //heap.print();
        for (int i = 0; i < k; i++) {
            res.push_back(heap.getMax());
            //heap.print();
        }

        return res;
    }
};
// @lc code=end

