/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
// Solution 1: DFS + BFS

// class Solution {
// public:
//     vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//     int shortestBridge(vector<vector<int>>& grid) {
//         int res = 0;
//         int n = grid.size();
//         pair<int, int> start = {0, 0};

//         // Step 1. find the first point of 1 to start
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     continue;
//                 }

//                 start.first = i;
//                 start.second = j;
//             }

//             if (start.first != 0) {
//                 break;
//             }
//         }

//         queue<int> qt;
//         dfs(grid, start.first, start.second, qt);

//         while (!qt.empty()) {
//             int size = qt.size();
//             for (int i = 0; i < size; i++) {
//                 int point = qt.front(); qt.pop();
//                 for (auto dir : dirs) {
//                     int x = point / n + dir[0];
//                     int y = point % n + dir[1];

//                     if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 2) {
//                         continue;
//                     } else if (grid[x][y] == 1) {
//                         return res;
//                     }

//                     grid[x][y] = 2;
//                     qt.push(x * n + y);
//                 }
//             }

//             res++;
//         }

//         return res;
//     }

//     void dfs(vector<vector<int>>& grid, int x, int y, queue<int>& qt) {
//         int n = grid.size();

//         if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 || grid[x][y] == 2) {
//             return;
//         }

//         // Because there are only two lands in a grid, use 2 representive as one
//         // and 1 is another.
//         grid[x][y] = 2;
//         qt.push(x * n + y);

//         for (auto dir : dirs) {
//             dfs(grid, (x + dir[0]), (y + dir[1]), qt);
//         }
//     }
// };

// Solution: Doubly BFS
class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;

        queue<int> qt, que;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                grid[i][j] = 3; // as start point
                qt.push(i * n + j);
                break;
            }

            if (!qt.empty()) {
                break;
            }
        }

        while (!qt.empty()) {
            int point = qt.front(); qt.pop();
            que.push(point); // for the next BFS to iterate     
            
            for (auto dir : dirs) {
                int x = point / n + dir[0];
                int y = point % n + dir[1];

                if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 || grid[x][y] == 2) {
                    continue;
                }

                grid[x][y] = 2;
                qt.push(x * n + y);
            }
        }

        while (!que.empty()) {
            // iterate the current level
            int size = que.size();

            for (int i = 0; i < size; i++) {
                int point = que.front(); que.pop();

                for (auto dir : dirs) {
                    int x = point / n + dir[0];
                    int y = point % n + dir[1];

                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 2) {
                        continue;
                    } else if (grid[x][y] == 1) {
                        return res;
                    }

                    grid[x][y] = 2;
                    que.push(x * n + y);
                }
            }

            res++;
        }

        return res;
    }
};
// @lc code=end

