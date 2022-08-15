/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

// Reference solution 1: https://ithelp.ithome.com.tw/m/articles/10213264
// Reference solution 2: https://www.cnblogs.com/grandyang/p/4481576.html

// Time complexity: sort O(N) and find solution with two pointers is O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        // Our purpose is finding out a + b + c = 0, a = -(b + c)
        for (int i = 0; i < nums.size() - 2; i++) { // use -2 for two other nums except for i itself
            // a should be handle the negative num, so that b and c are negative
            // therefore, their sum is 0
            if (nums[i] > 0) {
                break;
            }

            // Skip the same num as previous one to avoid the duplicated calculation
            if (i > 0 && (nums[i-1] == nums[i])) { 
                continue;
            }

            int target = -nums[i];      // find -nums[i] + nums[j] + nums[k] = 0
            int j = i + 1;              // start from the i + 1
            int k = nums.size() - 1;    // start from the end of the array

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    res.push_back( {nums[i], nums[j], nums[k]} );

                    // Avoid the dulicated num item for calculating
                    while (j < k && (nums[j] == nums[j+1])) {
                        j++;
                    }

                    while (j < k && (nums[k] == nums[k-1])) {
                        k--;
                    }

                    j++;
                    k--;
                } else if (nums[j] + nums[k] > target) {
                    // when nums[j] + nums[k] > target, it means 
                    // we need find a smaller num for the sum 
                    // so that it can be matched a+b+c = 0
                    // and k we defined it located the biggest num
                    // whieh is in the sorted array, therefore,
                    // we just move k to find the smaller num
                    k--;
                } else { // (nums[j] + nums[k] < target)
                    // move j the find the bigger num for the sum
                    j++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

