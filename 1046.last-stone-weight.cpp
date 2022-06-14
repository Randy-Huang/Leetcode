/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int *arr;
    int heapSize;
    int capacity;

    void createPriorityQueue(int size) {
        arr = new int[size];
        capacity = size;
        heapSize = -1;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    void shiftUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)] );
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int topIndex = i;

        int l = left(i);
        if (l <= heapSize && arr[l] > arr[topIndex]) {
            topIndex = l;
        }

        int r = right(i);
        if (r <= heapSize && arr[r] > arr[topIndex]) {
            topIndex = r;
        }

        if (topIndex != i) {
            swap(arr[topIndex], arr[i]);
            shiftDown(topIndex);
        }
    }

    void insert(int p) {
        heapSize++;
        arr[heapSize] = p;

        shiftUp(heapSize);
    }

    void remove(int i) {
        arr[i] = arr[0] + 1;

        shiftUp(i);

        extractMax();
    }

    int extractMax() {
        int result = arr[0];

        arr[0] = arr[heapSize];
        heapSize--;

        shiftDown(0);
        return result;
    }

    int getMax() {
        return arr[0];
    }

    int lastStoneWeight(vector<int>& stones) {
        createPriorityQueue(stones.size());

        for(auto stone : stones) {
            insert(stone);
        }

        // cout << "Priority Queue : ";
        // int i = 0;
		// while (i <= heapSize) {
		// 		cout << arr[i] << " ";
		// 		i++;
		// }
		// cout << "\n";

        // printf("heap size: %d\n", heapSize );
        while (heapSize > 0) {
            int first = extractMax(); 
            int second = extractMax();
            int diff = abs(first - second);
            if (diff > 0) {
                insert(diff);
            }
        }

        return heapSize == -1 ? 0 : arr[0];
    }
};
// @lc code=end

