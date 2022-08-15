/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool hasCycled = false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // DFS
        // return dfs(numCourses, prerequisites);

        // BFS
        return bfs(numCourses, prerequisites);
    }

    bool bfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> indegree(numCourses, 0);

        // construct indegree array
        for (auto edge : prerequisites) {
            int to = edge[0];
            indegree[to]++;
            //printf("indegree[%d]: %d\n", to, indegree[to]);
        }

        // we use a queue to find a node which has no any other node 
        // to indegree it so that we can use it as the beginngin to traverse
        // because it has no other node to depend on it
        queue<int> que;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        int count = 0;
        while (!que.empty()) {
            int from = que.front(); que.pop();
            count++;

            for (int to : graph[from]) {
                // erery the next to node need to reduce 1 
                // when we traverse it
                // and if its indegree is to be 0
                // which means there is no other node depend on it
                indegree[to]--;
                if (indegree[to] == 0) {
                    que.push(to);
                }
            }
        }

        return count == numCourses;
    }

    bool dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses);
        vector<bool> path(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (hasCycled) {
                return false;
            }

            traversal(graph, i, path, visited);
        }

        return !hasCycled;
    }

    void traversal(vector<vector<int>>& graph, int start, vector<bool>& path, vector<bool>& visited) {
        if (path[start]) {
            hasCycled = true;
        }

        if (hasCycled || visited[start]) {
            return;
        }

        visited[start] = true;
        path[start] = true;

        for (auto course : graph[start]) {
            traversal(graph, course, path, visited);
        }

        path[start] = false;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        printf("size: %d\n", prerequisites.size());

        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
            printf("from: %d, to: %d\n", from, to);
        }

        return graph;
    }
};
// @lc code=end

