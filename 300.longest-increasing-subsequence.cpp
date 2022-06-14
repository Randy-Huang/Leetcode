/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// Reference: https://leetcode.com/problems/longest-increasing-subsequence/discuss/1644530/c%2B%2B-solution-using-binary-search
// Reference: http://wiki.csie.ncku.edu.tw/acm/course/LIS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return doRSK_LIS(nums);
    }

    int doRSK_LIS(vector<int>& nums) {
        vector<int> lis;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            if (lis.empty() || lis.back() < n) {
                lis.push_back(n);
            }  else {
                // *lower_bound(lis.begin(), lis.end(), n) = n;
                // int pos = lower_bound(lis.begin(), lis.end(), n) - lis.begin();
                int pos = binarySearch(lis, 0, lis.size() - 1, n);
                //printf("pos: %d, origin: %d, new: %d\n", idx, lis[idx], n);
                lis[pos] = n;
            }
        }

        return lis.size();
    }

    int binarySearch(vector<int>& lis, int begin, int end, int target) {
        int index_bound = 0;
        while (end >= begin) {
            int mid = end + (begin - end) / 2;
            if (lis[mid] == target) {
                return mid;
            }

            if (lis[mid] > target) {
                // target is in the left  
                index_bound = mid;
                end = mid - 1;
            } else {
                // target is in the right
                begin = mid + 1;
            }
        }

        return index_bound;
    }

    int dpLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // base case: dp[0] = 1

        int res = dp[0];
        for (int i = 0; i < nums.size(); i++) {
            for (int subseqIdx = 0; subseqIdx < i; subseqIdx++) {
                if (nums[i] > nums[subseqIdx]) {
                     dp[i] = max(dp[i], (dp[subseqIdx] + 1));
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

