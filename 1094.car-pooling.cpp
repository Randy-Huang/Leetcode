/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops = 0;
        for (vector<int> trip : trips ) {
            if (trip[2] > stops) {
                stops = trip[2];
            }
        }

        vector<int> diff(stops + 1, 0);
        for (vector<int> trip : trips) {
            int passengers = trip[0];

            // i, j which mean to pick up passengers at stops_i
            // and drop off them at stop_j
            int i = trip[1];
            int j = trip[2];
            // printf("i: %d, j :%d, passengers: %d\n", i , j, passengers);

            diff[i] += passengers;
            diff[j] -= passengers;
        }

        bool res = true;
        for (int i = 1; i < diff.size(); i++) {
            // printf("i: %d, diff[i-1]: %d, diff[i]: %d\n", i, diff[i-1], diff[i]);
            diff[i] = diff[i-1] + diff[i];
            if (diff[i-1] > capacity) {
                return false;
            }
        }

        return res;
    }
};
// @lc code=end

