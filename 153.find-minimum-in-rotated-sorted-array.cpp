/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
// Reference 1: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/582964/4-solutions-including-divide-and-conquer-binary-search-follow-up/
// Reference 2: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/166875/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }

    int binarySearch(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int lo = 0;
        int hi = nums.size() - 1;
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; 

            // We stop our search when we find the inflection point, when either of the two conditions is satisfied:
            // 1. nums[mid] > nums[mid + 1] Hence, mid+1 is the smallest.
            // 2. nums[mid - 1] > nums[mid] Hence, mid is the smallest.
            //
            // [4, 5, 6, 7, 2, 3]
            //           l  m  h
            // In the above example. With the marked left and right pointers. 
            // The mid element is 2. The element just before 2 is 7 
            // and 7>2 i.e. nums[mid - 1] > nums[mid]. 
            // Thus we have found the point of inflection and 2 
            // is the smallest element.

            // case 1: mid+1 is the smallest.
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // case 2: mid is the smallest.
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            if (nums[0] < nums[mid]) {
                // if the mid elements value is greater than the 0th element this means
                // the least value is still somewhere to the right as we are still dealing with
                // elements greater than nums[0]
                lo = mid + 1;
            } else {
                // if nums[0] is greater than the mid value then this means the smallest value
                // is somewhere to
                // the left
                hi = mid;
            }
        }

        return INT_MAX;
    }
};
// @lc code=end

