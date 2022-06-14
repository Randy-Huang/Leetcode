/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    int heapSize;
    int capacity;
    pair<int, int> arr[10000];

    void createPriorityQueue() {
        heapSize = -1;
    } 

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i + 2);
    }

    void shiftUp(int i) {
        while (i > 0 && arr[i].first > arr[parent(i)].first) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int top = i;

        int l = left(i);
        if (l <= heapSize && arr[l].first > arr[top].first) {
            top = l;
        }

        int r = right(i);
        if (r <= heapSize && arr[r].first > arr[top].first) {
            top = r;
        }

        if (i != top) {
            swap(arr[i], arr[top]);
            shiftDown(top);
        }
    }

    void insert(pair<int, int> val) {
        heapSize++;
        arr[heapSize] = val;
        shiftUp(heapSize);
    }

    pair<int, int> extractMax() {
        pair<int, int> result = arr[0];
        arr[0] = arr[heapSize];
        heapSize--;
        shiftDown(0);
        return result;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        createPriorityQueue();
        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++) {
            int length = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            insert({length, i});
            printf("size: %d", heapSize);
            if (heapSize + 1 > k) {
                printf("remove");
                extractMax();
            }
        }

        while (heapSize != -1) {
            pair<int, int> top = extractMax();
            result.push_back(points[top.second]);
        }

        return result;
    }
};
// @lc code=end

