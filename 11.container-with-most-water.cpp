/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int result = 0;

        while (start < end) {
            int width = end - start;
            int height = min(heights[start], heights[end]);
            int area = height * width;
            result = max(result, area);

            if (heights[start] >= heights[end]) {
                end--;
            } else {
                start++;
            }
        }

        return result;
    }
};
// @lc code=end

