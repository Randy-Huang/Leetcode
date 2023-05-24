/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // still is the same monotonic stack
            // but in this case we store the index
            // and use st.top() the last index - current index we iterate
            // to get the diff index
            res[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

