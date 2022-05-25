/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size() - 1);
    }

    TreeNode* recursive(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = end + (start - end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = recursive(nums, start, mid - 1);
        node->right = recursive(nums, mid + 1, end);
        return node;
    }
};
// @lc code=end

