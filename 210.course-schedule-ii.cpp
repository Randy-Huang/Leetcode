/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    bool hasCycled = false;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // DFS solution
        // return dfs(numCourses, prerequisites);

        // BFS
        return bfs(numCourses, prerequisites);
    }

    vector<int> bfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = generateGraph(numCourses, prerequisites);

        // Construc indegree array
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            int to = edge[0];
            indegree[to]++;
        }

        queue<int> que;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> res;
        while (!que.empty()) {
            int from = que.front(); que.pop();
            res.push_back(from);

            for (auto to : graph[from]) {
                indegree[to]--;
                
                if (indegree[to] == 0) {
                    que.push(to);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }

        return {};
    }

    vector<int> dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = generateGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses);
        vector<bool> path(numCourses);
        vector<int> postorder;

        for (int i = 0; i < numCourses; i++) {
            traversal(graph, i, visited, path, postorder);
        }
        
        if (hasCycled) {
            return {};
        }

        vector<int> res;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            res.push_back(postorder[i]);
        }

        return res;
    }

    void traversal(vector<vector<int>>& graph, int start, vector<bool>& visited, vector<bool>& path, vector<int>& postorder) {
        if (path[start]) {
            hasCycled = true;
        }

        if (hasCycled || visited[start]) {
            return;
        }
       
        visited[start] = true;
        path[start] = true;
        for (auto course : graph[start]) {
            traversal(graph, course, visited, path, postorder);
        }
        
        // for traversal topological sorting
        // because every child sub tasks need to be visited
        // so that we just visit their root
        // and postorder should be fit the case to traverse
        postorder.push_back(start);
        path[start] = false;
    }

    vector<vector<int>> generateGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to); 
        }
        
        return graph;
    }
};
// @lc code=end

