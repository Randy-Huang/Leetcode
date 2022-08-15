/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    static bool sortAscendingOrder(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // 1 is end position in an array
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), sortAscendingOrder);

        int res = 0;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] > intervals[i][0]) {
                res++;
            } else {
                current = intervals[i];
            }
        }

        return res;
    }
};
// @lc code=end

