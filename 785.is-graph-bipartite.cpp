/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartiteGraph = true;

    bool isBipartite(vector<vector<int>>& graph) {
        return bfs(graph);
    }

    bool bfs(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n);
        vector<bool> color(n);

        for (int i = 0; i < n; i++) {
            if (!isBipartiteGraph) {
                return false;
            }

            traversal(graph, i, visited, color);
        }

        return true;
    }

    void bfsTraversal(vector<vector<int>>& graph, int start, vector<bool>& visited, vector<bool>& color) {
        visited[start] = true;

        queue<int> que;
        que.push(start);

        while (!que.empty() && !isBipartiteGraph) {
            int u = que.front(); que.pop();
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    color[v] = !color[u];
                    que.push(v);
                } else {
                    if (color[u] == color[v]) {
                        isBipartiteGraph = false;
                        return;
                    }
                }
            }
        }
    }

    bool dfs(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> visited(n, false);
        vector<bool> color(n, false);

        for (int i = 0; i < n; i++) {
            traversal(graph, i, visited, color);
        }

        return isBipartiteGraph;
    }

    void traversal(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<bool>& color) {
        visited[u] = true;

        for (auto v : graph[u]) {
            if (!isBipartiteGraph) {
                return;
            }

            if (!visited[v]) {
                color[v] = !color[u];
                traversal(graph, v, visited, color);
            } else {
                if (color[v] == color[u]) {
                    isBipartiteGraph = false;
                    return;
                }
            }
        }
    }
};
// @lc code=end

