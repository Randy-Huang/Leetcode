/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<int> res;

        // adjancency list
        vector<unordered_set<int>> adjList(n);
        
        // Step 1: build adjancency list from graph
        for (vector<int>& edge : edges) {
            // undirected graph
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }

        // Step 2: First we handle the directed tree from all leaves to root using queue
        // when adjList[i].size() == 1 which means adjList[i] is a leave node
        queue<int> que; // use instead of degree
        for (int i = 0; i < n; i++) {
            if (adjList[i].size() == 1) {
                que.push(i);
            }
        }

        // Step 3: start to iterate all leaves from queue and erase them from the adjancency list
        // if adjList[i].size() == 1, we push it and iterate again until n <= 1
        while (n > 2) {
            int size = que.size();
            n -= size;

            for (int i = 0; i < size; i++) {
                int from = que.front(); que.pop();
                for (int to : adjList[from]) {
                    adjList[to].erase(from); 

                    if (adjList[to].size() == 1) {
                        que.push(to);
                    }
                }
            }
        }

        // Step 4: the rest of nodes are the MHT's root
        while (!que.empty()) {
            res.push_back(que.front()); que.pop();
        }

        return res; 
    }
};
// @lc code=end

