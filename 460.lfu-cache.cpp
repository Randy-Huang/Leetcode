/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class Data {
public:
    int key;
    int value;
    int usage;
    int timestamp;

    Data(int k, int v, int t) {
        key = k;
        value = v;
        timestamp = t;
        usage = 0;
    }
};

class MinHeap {
public:
    vector<pair<int /* Data key */, Data* /* Data include usage */>> cache;
    int heap_size;

    MinHeap() = default;

    MinHeap(int capacity) {
        heap_size = -1;
        cache = vector<pair<int, Data*>>(capacity);
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i ) {
        return 2 * i + 2; 
    }

    void swap(pair<int, Data*>& a, pair<int, Data*>& b) {
        pair<int, Data*> temp = a;
        a = b;
        b = temp;
    }

    bool needSwapData(pair<int, Data*>& a, pair<int, Data*>& b) {
        Data* data1 = a.second;
        Data* data2 = b.second;

        if (data1->usage <= data2->usage) {
            if (data1->usage == data2->usage) {
                if (data1->timestamp < data2->timestamp) {
                    return true;
                }
            } else {
                return true;
            }
        }

        return false;
    }

    void shiftUp(unordered_map<int, int>& indices, int i) {
        while (i > 0 && needSwapData(cache[i], cache[parent(i)])) {
            indices[ cache[parent(i)].first ] = i;
            indices[ cache[i].first ] = parent(i);
            swap(cache[i], cache[parent(i)]);
            i = parent(i);
        }
    }

    void shiftDown(unordered_map<int, int>& indices, int i) {
        int top = i;

        int l = left(i);
        if (l <= heap_size && needSwapData(cache[l], cache[top])) {
            top = l;
        }

        int r = right(i);
        if (r <= heap_size && needSwapData(cache[r], cache[top])) {
            top = r;
        }

        if (i != top) {
            indices[ cache[top].first ] = i;
            indices[ cache[i].first ] = top;
            swap(cache[i], cache[top]);
            shiftDown(indices, top);
        }
    }

    int extractMin(unordered_map<int, int>& indices) {
        int key = cache[0].first;
        cache[0] = cache[heap_size];
        heap_size--;
        shiftDown(indices, 0);
        return key;
    }

    int get(unordered_map<int, int>& indices, int position, int timestamp) {
        Data* data = cache[position].second;
        int res = data->value;
        
        // Change priority
        data->usage = data->usage + 1;
        data->timestamp = timestamp;
        shiftDown(indices, position);

        return res;
    }

    void insert(unordered_map<int, int>& indices, Data* data) {
        heap_size++;
        cache[heap_size] = make_pair(data->key, data);
        shiftUp(indices, heap_size);
    }

    void update(unordered_map<int, int>& indices, int position, int value, int timestamp) {
        Data* data = cache[position].second;
        data->value = value;

        // Change priority
        data->usage = data->usage + 1;
        data->timestamp = timestamp;
        shiftDown(indices, position);
    }

    void display(unordered_map<int, int>& indices) {
        for (int i = 0; i < heap_size + 1; i++) {
            Data* data = cache[i].second;
            printf("priority: %d, key: %d, value: %d, timestamp: %d, pos: %d, dict: %d\n", data->usage, data->key, data->value, data->timestamp, indices[data->key]);
        }
    }

    int getCacheSize() {
        return heap_size;
    }
};

class LFUCache {
public:
    int ERROR = -1;

    int capacity;

    int timestamp;

    MinHeap priorityQueue;
    unordered_map<int /* Data key */, int /* index */> indices;

    LFUCache(int cap) {
        capacity = cap;
        priorityQueue = MinHeap(cap);
        indices = unordered_map<int, int>(cap);
        timestamp = 0;
    }
    
    int get(int key) {
        //printf("get, key: %d\n", key);

        timestamp++;
        if (indices.find(key) == indices.end()) {
            //printf("geterror \n");
            return ERROR;
        } else {
            int position = indices[key];
            int res = priorityQueue.get(indices, position, timestamp);
            //printf("get result return: %d\n", res);
            return res;
        }
    }
    
    void put(int key, int value) {
        //printf("put, key: %d, value: %d, size: %lu\n", key, value, indices.size());
        if (capacity == 0) {
            return;
        }

        timestamp++;
        if (indices.find(key) != indices.end()) {
            //printf("update queue\n");
            int position = indices[key];
            priorityQueue.update(indices, position, value, timestamp);
            return;
        }

        if (indices.size() == capacity) {
            int key = priorityQueue.extractMin(indices);
            //printf("queue is full, need remove key: %d\n", key);
            indices.erase(key);
        }

        Data* data = new Data(key, value, timestamp);
        indices[key] = priorityQueue.getCacheSize() + 1;
        priorityQueue.insert(indices, data);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

