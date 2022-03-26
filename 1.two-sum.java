/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for ( int i = 0; i < nums.length; i++ ) 
        {
            map.put(nums[i], i);
        }
        for (int j = 0; j < nums.length; j++) 
        {
            int complement = target - nums[j];
            if ( map.containsKey( complement ) &&  map.get(complement) != j ) 
            {
                return new int[] { j, map.get( complement ) };
            }
        }

        return null;
    }
}
// @lc code=end

