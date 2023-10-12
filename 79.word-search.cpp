/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool found = false;

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //printf("m: %d, n: %d\n", m , n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(i, j, board, word, 0, visited);
                if (found) {
                    return true;
                }
            }
        }

        return false;
    }

    void search(int i, int j, vector<vector<char>>& board, string word, int idx, vector<vector<bool>>& visited) {
        if (idx == word.size()) {
            found = true;
            return;
        }

        if (found) {
            return;
        }

        //printf("i: %d, j: %d, idx: %d\n", i, j, idx);
        int m = board.size();
        int n = board[0].size();
        if (i >= m || i < 0 || j >=n || j < 0 || (board[i][j] != word[idx]) || visited[i][j]) {
            return;
        }

        // backtracing here
        visited[i][j] = true;
        search(i + dirs[0][0], j + dirs[0][1], board, word, (idx + 1), visited);
        search(i + dirs[1][0], j + dirs[1][1], board, word, (idx + 1), visited);
        search(i + dirs[2][0], j + dirs[2][1], board, word, (idx + 1), visited);
        search(i + dirs[3][0], j + dirs[3][1], board, word, (idx + 1), visited);
        visited[i][j] = false;
    }
};
// @lc code=end

