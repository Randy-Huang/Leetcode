/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        traversal(graph, 0, res, path);
        return res;
    }

    void traversal(vector<vector<int>>& graph, int start, vector<vector<int>>& res, vector<int>& path) {
        path.push_back(start);

        int n = graph.size();
        if (start == (n - 1)) {
            printf("start: %d, n: %d\n", start, n);
            res.push_back(path);
        }

        for (int v : graph[start]) {
            traversal(graph, v, res, path);
        }

        path.pop_back();
    }
};
// @lc code=end

