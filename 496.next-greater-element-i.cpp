/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater = nextGreaterElement(nums2);
        unordered_map<int, int> greaterMap;

        for (int i = 0; i < nums2.size(); i++) {
            // use hashmap to resotre key which is in the nums2 
            // and value is the key's the next greater value
            greaterMap.insert({nums2[i], greater[i]});
        }

        vector<int> res; 
        for (int i = 0;  i < nums1.size(); i++) {
            res.push_back(greaterMap[nums1[i]]);
        }

        return res;
    }

    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;

        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return res;
    }
};
// @lc code=end

