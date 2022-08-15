/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Reference: https://www.cnblogs.com/grandyang/p/4267628.html
class Solution {
public:
    // Core thinking: it's difficult to do the graph copy is that
    // we not only copy node but also its neighbor nodes in a vector
    // how do we prevent copy the same node from them
    // we can use the map to record we iterate nodes to see if
    // the current node does copy

    Node* cloneGraph(Node* node) {
        return bfs(node);
    }

    // BFS
    Node* bfs(Node* node) {
        if (!node) {
            return NULL;
        }

        unordered_map<Node*, Node*> map;
        bfsTraversal(map, node);
        return map[node];
    }

    void bfsTraversal(unordered_map<Node*, Node*>& map, Node* node) {
        Node* clone = new Node(node->val);
        map[node] = clone;
        
        queue<Node*> que;
        que.push(node);

        while (!que.empty()) {
            Node* current = que.front(); que.pop();
            
            // 1. clone node if it is not in the map
            // 2. add new node to the vector of the current neighbor 

            for (auto neighbor : current->neighbors) {
                if (!map.count(neighbor)) {
                    Node* clone = new Node(neighbor->val);
                    map[neighbor] = clone;
                    que.push(neighbor);
                }

                map[current]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    // DFS
    Node* dfs(Node* node) {
        unordered_map<Node*, Node*> map;
        dfsTraversal(map, node);
        return map[node];
    }

    void dfsTraversal(unordered_map<Node*, Node*>& map, Node* node) {
        if (!node) {
            return;
        }

        if (map.count(node)) {
            return;
        }

        Node* clone = new Node(node->val);
        map[node] = clone;

        for (auto neighbor : node->neighbors) {
            dfsTraversal(map, neighbor);
            clone->neighbors.push_back(map[neighbor]);
        }
    }
};
// @lc code=end

