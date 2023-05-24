/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n, -1);
        stack<int> st;

        for (int i = (2 * n - 1); i >= 0; i--) {
            int index = i % n;

            while (!st.empty() && nums[index] >= st.top()) {
                st.pop();
            }
            
            res[i % n] = res[index] != -1 ? res[index] : (st.empty() ? -1 : st.top());
            st.push(nums[index]);
        }

        return res;
    }
};
// @lc code=end

