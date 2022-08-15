/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/5294255.html
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res{0};

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                res.push_back(res[i / 2]);
            } else {
                res.push_back(res[i / 2] + 1);
            }
        }

        return res;
    }
};
// @lc code=end

