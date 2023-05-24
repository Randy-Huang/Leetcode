/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// Solution 1: use hash table (unordered_map)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int, int> m;
//         int res = 0;

//         for (int num : nums) {
//             if (m.count(num)) {
//                 continue;
//             }

//             // m[left] means the count of a left number
//             // last time we have a sequence we arrived at
//             // from a number to the left edge
//             int leftCount = m.count(num -1) ? m[num - 1] : 0;

//             // m[right] means the count of a right number
//             // last time we have a sequence we arrived at
//             // from a number to the right edge
//             int rightCount = m.count(num + 1) ? m[num + 1] : 0;
            
//             // connect two sub consecutive sequences and 
//             // and also need to add 1 which means num itself
//             int count = leftCount + rightCount + 1;

//             m[num] = count; 
//             // Notice that when we connect two sub sequence, we not only consider
//             // that we need to update the new count to the current number we iterate 
//             // but also find the right and left edge of a new subsequence because
//             // we need to update them for the new length.
//             //
//             // How do we find and update both of them for a new subsequence?
//             // we've had leftCount and rightCount, which mean  they are
//             // edges of some subsequences.
//             // use [num - left] we can find the left edge of a subsequence
//             // use [num + right] we can find the right edge of a subsequence
//             // num - left means the current num to the left edge,
//             // num + right means the current num to the right edge.
//             // for example:
//             // [1, 2, 3, 4] and [6, 7] and current num [5]
//             // leftCount = m[5-1] = m[4] = 4
//             // leftCount = m[5+1] = m[6] = 2
//             // m[5] = 4 + 2 + 1 = 7
//             // m[5-4] = m[1] = 7
//             // m[5+2] = m[7] = 7
//             m[num - leftCount] = count;
//             m[num + rightCount] = count;

//             res = max(res, count);
//         }

//         return res;
//     }
// };

// Solution 2: use hash table (unordered_set)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); // add all numbers to a set

        int maxRes = 0;
        for (int num : nums) {
            // if we can find a number which is before the current number
            // then we should keep iterate the previous number to as its start point
            // until we find a number which is the start point of a subsequence
            if (s.find(num - 1) == s.end()) { 
                int current = num;
                int currentMax = 1;

                // Try to find the end point of a subsequence
                while(s.find(current + 1 ) != s.end()) {
                    current++;
                    currentMax++;
                }

                maxRes = max(currentMax, maxRes);
            }
        }

        return maxRes;
    }
};

// @lc code=end

