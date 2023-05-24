/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> res;
        vector<int> mergeInterval(2);
        mergeInterval[0] = newInterval[0];
        mergeInterval[1] = newInterval[1];

        int pos = 0;

        for (auto& interval : intervals) {
            // Part 1, the beginning of these intervals
            if (newInterval[0] > interval[1]) {
                // |---| |----|
                //              |---| new
                res.push_back(interval);
                pos++;
                continue;
            }

            // Part 2, the end of these intervals
            if (newInterval[1] < interval[0]) {
                //       |---| |----|
                // |---| new
                res.push_back(interval);
                continue;
            }

            // Part 3. overlap region in the middle of these intervals
            // case 1.
            // |---| |---| |---|
            //    |---------| new
            //
            // case 2. 
            // |---| |---| |---|
            //    |---------------| new
            //
            // case 3
            //   |---| |---| |---|
            // |---------| new
            //
            // case 4
            //   |---| |---| |---|
            // |--------------------| new
            mergeInterval[0] = min(mergeInterval[0], interval[0]);
            mergeInterval[1] = max(mergeInterval[1], interval[1]);
        }

        res.insert(res.begin() + pos, mergeInterval);

        return res;
    }
};
// @lc code=end

