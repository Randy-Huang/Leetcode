/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        return dp(nums);
    }

    public int divideAndConquer(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        return divideAndConquerHelper(nums, 0, nums.length - 1);
    }

    private int divideAndConquerHelper(int[] nums, int left, int right) {
        // 1. Check the validation of bound
        if (left > right) {
            return Integer.MIN_VALUE;
        }

        int mid = (left + right) >>> 1;

        // 1. the sum of the left of nums
        int subLeftSum = divideAndConquerHelper(nums, left, mid - 1);

        // 2. the sum of the right of nums
        int subRightSum = divideAndConquerHelper(nums, mid + 1, right);

        // 3. the sum of crossing left and right of the mid in nums
        // 3.1 left surfix maxSum start from index (mid - 1) to left
        int sum = 0;
        int maxLeftSum = 0;
        for (int i = mid - 1; i >= left; i-- ) {
            sum += nums[i];
            maxLeftSum = Math.max(sum, maxLeftSum);
        }

        // 3.2 right prefix maxSum start from index mid + 1 to right
        sum = 0;
        int maxRightSum = 0;
        for (int i = mid + 1; i <= right ;i++) {
            sum += nums[i];
            maxRightSum = Math.max(sum, maxRightSum);
        }

        // max(subLeftSum, maxRightSum, crossSum)
        return Math.max((maxLeftSum + maxRightSum + nums[mid]), Math.max(subLeftSum, subRightSum));
    }

    public int dp(int[] nums) {
        // dp[i] expresses the max sub sum by the index i
        // dp[i] = max(dp[i - 1] + nums[i], nums[i])

        // amout of sub sum from index, it expresses dp[i]
        int currentSumByPosition = nums[0];

        // global sub sum
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentSumByPosition = Math.max((currentSumByPosition + nums[i]), nums[i]);
            maxSum = Math.max(maxSum, currentSumByPosition);
        }

        return maxSum;
    }
}
// @lc code=end

