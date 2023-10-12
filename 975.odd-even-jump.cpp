/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 */

// @lc code=start
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        int res = 1; // the final elelemt is one of solutions

        // Definition:
        // The current that is in index i have two states:
        // positive jump state: to jump to final point
        // negative jump state: to jump to final point
        vector<vector<int>> dp(n, vector<int>(2));

        // base case
        dp[n - 1][0] = res;
        dp[n - 1][1] = res;

        map<int /* value */, int /* index */> mp;
        mp[arr[n-1]] = n - 1;

        // we've already know the final element arr[n - 1] 
        // must be a solution, so we just iterate reservely 
        // every element to see their own two individual states
        // we don't need to start from index n - 1, just start from n - 2
        for (int i = n - 2; i >= 0; i--) {
            // positive jump which arr[i] <= arr[j]
            auto pJump = mp.lower_bound(arr[i]);
            if (pJump != mp.end()) {
                dp[i][0] = dp[pJump->second][1];
            }

            // negative jump which arr[i] >= arr[j]
            auto nJump = mp.upper_bound(arr[i]);
            if (nJump != mp.begin()) {
                // use upper_bound(A) to get value 
                // which is the first value that greater than A
                // if we let upper_bound(A) - 1, we'll get the result
                // which is the final value that are smaller or 
                // equal to A
                //
                // 1. use prev(A) to get the previous element of upper_bound(A)
                // dp[i][1] = dp[prev(nJump)->second][0];
                //
                // 2. use upper_bound(A) - 1
                nJump--;
                dp[i][1] = dp[nJump->second][0];
            }

            mp[arr[i]] = i;
            if (dp[i][0]) {
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

