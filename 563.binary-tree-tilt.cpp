/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int findTilt(TreeNode* root) {
        // The result of Sum of every tilt
        int res = 0;
        recursive(root, res);
        return res;
    }

    int recursive(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }

        int left = recursive(root->left, res);
        int right = recursive(root->right, res);

        res += abs(left - right);
        int sum = root->val + left + right;
        
        return sum;
    }
};
// @lc code=end

