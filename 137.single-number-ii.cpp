/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start

// Reference: https://ithelp.ithome.com.tw/m/articles/10242654
// Reference: https://xiaotaoguo.com/p/leetcode-137/
// Reference: https://leetcode-cn.com/problems/single-number-ii/comments/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return solution2(nums);
    }

    int solution2(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0; 
            // count the times that every value in nums 
            // in specified bit index 
            for (auto num : nums) {
                count += (num >> i) & 0x1; 
            } 
            
            // modulo 3 and put the result to the specified bit
            res |= ((count % 3) << i);
        }

        return res;
    }

    int solution1(vector<int>& nums) {
        // use the relation
        // x & ~x = 0 
        // x & ~0 = x

        int one = 0;
        int two = 0;

        for (int num : nums) {
            // for example: [1, 1, 1]
            // before for loop: 00
            // i=0: 01 
            // i=1: 10 
            // i=2: 00
            // 00 -> 01 -> 10 -> 00
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
            //printf("one: %d, two: %d\n", one, two);
        }

        return one;
    }
};
// @lc code=end

