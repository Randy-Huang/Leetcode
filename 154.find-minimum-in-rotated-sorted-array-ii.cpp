/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // The big difference between 153 and 154 is that, if an array has 
        // lots of duplicated num, we couldn't use binary search because 
        // it doesn't know which side has the part of the smaller size in subarray
        // so in this case, the time complexity cannot be O(logn), it must be O(n)

        //return divideAndConquer(nums, 0, nums.size() - 1);
        return binarySearchWithShift(nums);
    }

    int binarySearchWithShift(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        int lo = 0;
        int hi = size - 1;
        if (nums[lo] < nums[hi]) {
            return nums[0];
        }
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            // {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2} 
            // {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2}
            if (nums[hi] < nums[mid]) {
                lo = mid + 1;
            } else if (nums[lo] > nums[mid]) {
                hi = mid;
            } else {
                hi--;
            }
        }

        return nums[hi]; // reutnr nums[lo] should work as well
    }

    int divideAndConquer(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }

        // Need to be carefully, 
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }

        int mid = lo + (hi - lo) / 2;
        return min(divideAndConquer(nums, lo, mid), divideAndConquer(nums, mid + 1, hi));
    }
};
// @lc code=end

