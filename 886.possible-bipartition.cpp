/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool isBipartition = true;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        return dfs(n, dislikes);
    }

    vector<vector<int>> generateGraph(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for (auto edge : dislikes) {
            int v = edge[0];
            int u = edge[1];

            // an undirected graph
            graph[v].push_back(u);
            graph[u].push_back(v);
        }

        return graph;
    }

    bool dfs(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph = generateGraph(n, dislikes);

        // node is from 1
        vector<bool> visited(n + 1);
        vector<bool> color(n + 1);

        for (int i = 1 ; i <= n; i++ ) {
            if (!isBipartition) {
                return false;
            }

            traversal(graph, i, visited, color);
        }

        return true;
    }

    void traversal(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<bool>& color) {
        visited[u] = true;

        for (auto v : graph[u]) {  
            if (!visited[v]) {
                color[v] = !color[u];
                traversal(graph, v, visited, color);
            } else {
                if (color[u] == color[v]) {
                    isBipartition = false;
                    return;
                }
            }
        }
    }
};
// @lc code=end

