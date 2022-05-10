/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:

    // Solution 2: use "C(n, k) = C(n-1, k-1) + C(n-1, k)", where 0 <= k <= n
    vector<vector<int>> combine(int n, int k) {
        if (0 > k || k > n) {
            printf("return\n");
            return {};
        }

        if (k == 0) {
            printf("return total\n");
            return {{}};
        }

        printf("n = %d, k = %d\n", n,k);

        // 1. C(n-1, k-1)
        vector<vector<int>> res = combine(n-1, k-1); 
        printf("Round 1\n");
        for (auto& a : res) {
            a.push_back(n);
            for (auto elem: a)
            {
                cout<<elem<<", ";
            }
            cout<<endl;
        }
         printf("go to 2\n");
        // 2. C(n-1, k)
        vector<vector<int>> res2 = combine(n-1, k);
        printf("Round 2\n");
        for (auto &a : res2) {
            res.push_back(a);
            for (auto elem: a)
            {
                cout<<elem<<", ";
            }
            cout<<endl;
        }

        return res;
    }

    // Solution 1
    // vector<vector<int>> res;

    // vector<vector<int>> combine(int n, int k) {
    //     vector<int> track;
    //     backtrack(track, n, k, 1);
    //     return res;
    // }

    // void backtrack(vector<int>& track, int n, int k, int start) {
    //     if (track.size() == k) {
    //         res.push_back(track);
    //         return;
    //     }

    //     for (int i = start; i <= n; i++) {
    //         track.push_back(i);
    //         backtrack(track, n, k, i + 1);
    //         track.pop_back();
    //     }
    // }
};
// @lc code=end

