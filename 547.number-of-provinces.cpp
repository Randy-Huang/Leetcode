/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        int res = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int x = find(parent, i);
                    int y = find(parent, j);

                    if (x != y) {
                        union_operation(parent, x, y);
                        res--;
                    }
                }
            }
        }

        return res;
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }

        return find(parent, parent[i]);
    }

    void union_operation(vector<int>& parent, int x, int y) {
        parent[x] = y;
    }
};
// @lc code=end

