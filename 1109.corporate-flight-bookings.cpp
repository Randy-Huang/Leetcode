/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);

        // Calculate diff for each booking
        for (vector<int> booking : bookings) {
            int i = booking[0];
            int j = booking[1];
            int seats = booking[2];
           
            diff[i-1] += seats;
            if ((j) < n)  {
                diff[j] -= seats;
            }
            
        }

        for (int i = 1; i < n; i++) {
            diff[i] = diff[i-1] + diff[i];
        }

        return diff;
    }
};
// @lc code=end
