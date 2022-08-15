/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class Node {
public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
    }
};

class DoublyLinkedList {
public:
    int size;

    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = new Node(0, -1);
        tail = new Node(0, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Add new node to the tail
    // Time complexity: O(1)
    void addLast(Node* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    // Remove node
    // Time complexity: O(1)
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    // Time complexity: O(1)
    Node* removeFirst() {
        if (head->next == tail) {
            return NULL;
        }

        Node* first = head->next;
        remove(first);
        return first;
    }

    int length() {
        return size;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> hashmap;
    DoublyLinkedList list;

    int cap;

    int KEY_UNKNOWN = -1;

    LRUCache(int capacity) {
        hashmap = unordered_map<int, Node*>();
        cap = capacity;
    }
    
    int get(int key) {
        if (hashmap.find(key) == hashmap.end()) {
            return KEY_UNKNOWN;
        }

        updateKey(key);
        Node* node = hashmap[key];
        return node->val;
    }
    
    void put(int key, int value) {
        if (hashmap.find(key) != hashmap.end()) {
            // Find corresponding key in the LRU cache, update the key as high priority
            // we need to remove it from the list, and add it to the latest
            deleteKey(key);
            add(key, value);
            return;
        }

        if (cap <= list.length()) {
            removeLeastRecently();
        }

        add(key, value);
    }

    void add(int key, int val) {
        Node* node = new Node(key, val);
        list.addLast(node);
        hashmap[key] = node;
    }

    void updateKey(int key) {
        Node* node = hashmap[key];
        list.remove(node);
        list.addLast(node);
    }

    void deleteKey(int key) {
        Node* node = hashmap[key];
        list.remove(node);
        hashmap.erase(key);
    }

    void removeLeastRecently() {
        Node* node = list.removeFirst();
        hashmap.erase(node->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

