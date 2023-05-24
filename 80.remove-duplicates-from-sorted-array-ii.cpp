/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start

// Reference: https://www.cnblogs.com/grandyang/p/4329295.html

// Solution 2: improve two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = 0;

        for (int next = 0; next < nums.size(); next++) {
            if (current < 2 || nums[next] > nums[current - 2]) {
                nums[current++] = nums[next];
            }
        }

        return current;
    }
};

// Solution 1: two pointers
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int res = 0;
        
//         int PAIR = 2;
//         int count = 1;

//         int current = 0;
//         for (int next = 0; next < nums.size(); next++) {
//             if (nums[next] == nums[current]) {
//                 if (count > PAIR) {
//                     continue;
//                 } else {
//                     count++;
//                     nums[res] = nums[next];
//                     res++;
//                 }
//             } else {
//                 count = 2;
//                 current = next;
//                 nums[res] = nums[next];
//                 res++;
//             }
//         }

//         return res == 0 ? 1 : res;
//     }
// };
// @lc code=end

