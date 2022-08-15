/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        // DFS
        return bfs(grid);
    }

    int dfs(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) {
            return;
        }

        int m = grid.size();
        int n = grid[0].size();

        visited[x][y] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if ((0 <= nx && nx < m) && (0 <= ny && ny < n) && !visited[nx][ny] && (grid[nx][ny] == '1')) {
                dfs(grid, visited, nx, ny);
            }
        }
    }

    int bfs(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    res++;
                }
            }

        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        visited[x][y] = true;

        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            pair<int, int> point = q.front(); q.pop();

            for (auto dir : directions) {
                int nx = dir.first + point.first;
                int ny = dir.second + point.second;

                if ((0 <= nx && nx < m) && (0 <= ny && ny < n) && !visited[nx][ny] && (grid[nx][ny] == '1')) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
};
// @lc code=end

