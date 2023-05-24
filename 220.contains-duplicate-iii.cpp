/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4545261.html
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // use map because STL map data structure is implemented by
        // black-red tree and key-value pair will be sorted
        // map<long long, int> diff; /* {diff, index}*/
        set<long long> diff;

        int left = 0;
        for (int right = left; right < nums.size(); right++) {
            // 1. find out what invalid k length we need to remove first
            if (right - left > k) {
                // case (right - left) > k
                // not satisfy the condition abs(i - j) <= k, 
                // the element which is in the position no more need to match the k
                // we just ignore
                diff.erase(nums[left++]);
            }

            // 2. compare elements what pair can satisfy "abs(nums[i] - nums[j])"
            // case (right - left) <= k 
            // find the threshold "nums[j] - t"
            // use lower_bound(key), it can helps us
            // to find out the first element which greater than or equal to key (nums[right] - t)
            auto iterator = diff.lower_bound((long long) nums[right] - t);

            // when we use lower_bound(key), it it cannot find any subset can be satified,
            // the *iterator will be 1 == diff.end()
            if (iterator != diff.end() && (abs(nums[right] - *iterator) <= t)) {
                return true;
            }

            diff.insert(nums[right]);
        }

        return false;
    }
};
// @lc code=end

