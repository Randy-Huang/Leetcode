/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start

// Reference: https://blog.csdn.net/fuxuemingzhu/article/details/82917037
class Solution {
public:
    // Using DFS
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();

        // record what the visited points can flow from low to high location
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int x, int y) {
        int m = matrix.size();
        int n = matrix[0].size();

        ocean[x][y] = true;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // in our case
            // we need to find the intersection between pacific vector
            // and atlantic vector where the flow is from low to high
            // it's not the same as question metioned the flow from high to low
            // our purpose is to find matrix[nx][ny] the new point whether
            // it is bigger than or equal to the old point matrix[x][y]
            if ((0 <= nx && nx < m) && (0 <= ny && ny < n) && (!ocean[nx][ny]) && (matrix[x][y] <= matrix[nx][ny])) {
                dfs(matrix, ocean, nx, ny);
            }
        }
    }
};
// @lc code=end

