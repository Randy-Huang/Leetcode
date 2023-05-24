/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
// DFS
// class Solution {
// public:
//     int regionsBySlashes(vector<string>& grid) {
//         int n = grid.size();
//         vector<vector<int>> pixels(3 * n, vector<int>(3 * n));

//         // build a graph of pixels
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '/') {
//                     pixels[3 * i][3 * j + 2] = 1;
//                     pixels[3 * i + 1][3 * j + 1] = 1;
//                     pixels[3 * i + 2][3 * j] = 1;
//                 } else if (grid[i][j] == '\\') {
//                     pixels[3 * i][3 * j] = 1;
//                     pixels[3 * i + 1][3 * j + 1] = 1;
//                     pixels[3 * i + 2][3 * j + 2] = 1;
//                 }
//             }
//         }

//         // iterate graph to find region count by 0
//         int res = 0;
//         for (int i = 0; i < pixels.size(); i++) {
//             for (int j = 0; j < pixels.size(); j++) {
//                 if (pixels[i][j] == 0) {
//                     dfs(pixels, i, j);
//                     res++;
//                 }
//             }
//         }

//         return res;
//     }

//     void dfs(vector<vector<int>>& pixels, int i, int j) {
//         // bound check
//         if (i >= 0 && j >= 0 && i < pixels.size() && j < pixels.size()) {
//             if (pixels[i][j] == 0) {
//                 pixels[i][j] = 1;
//                 dfs(pixels, i + 1, j);
//                 dfs(pixels, i - 1, j);
//                 dfs(pixels, i, j + 1);
//                 dfs(pixels, i, j - 1);
//             }
//         }
//     }
// };

// union-find
class UnionFind {
public:
    UnionFind(int size) {
        parents = vector<int>(size);
        for (int i = 0; i < parents.size(); i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void union_op(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parents[px] = py;
        }
    }
private:
    vector<int> parents;
};


class Solution {
public:
        /*  
                      north (0)
                    |----------| 
                    |\        /|
                    | \      / |
                    |  \    /  |
                    |   \  /   |
         west (3)   |    \/    |    east (1)
                    |    /\    |
                    |   /  \   |
                    |  /    \  |
                    | /      \ |
                    |/        \|    
                    |----------|
                      south (2)
        */
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = 4 * n * n;

        UnionFind unionFind(size);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int base = 4 * (i * n + j);

                // Step 1: unite triangles in a single square
                if (grid[i][j] == '/') {
                    unionFind.union_op(base, base + 3);
                    unionFind.union_op(base + 1, base + 2);
                } else if (grid[i][j] == '\\') {
                    unionFind.union_op(base, base + 1);
                    unionFind.union_op(base + 2, base + 3);
                } else { // grid[i][j] == ' '
                    unionFind.union_op(base, base + 1);
                    unionFind.union_op(base + 1, base + 2);
                    unionFind.union_op(base + 2, base + 3);
                }

                // Step 2: unite adjcent square
                if (i > 0) { // upper side
                    int upper = 4 * ((i - 1) * n + j) + 2;
                    unionFind.union_op(base, upper);
                }

                if (j > 0) { // left side
                    int left = (4 * (i * n + (j - 1))) + 1; 
                    unionFind.union_op(base + 3, left);
                }
            }
        }

        int res = 0;
        for (int x = 0; x < size; x++) {
            if (x == unionFind.find(x)) {
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

