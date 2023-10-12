/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        recursive(root, sum);
        return root;
    }

    void recursive(TreeNode* root, int& rightSum) {
        if (root == nullptr) {
            return;
        }
    
        recursive(root->right, rightSum);
        // cout << "root: " << root->val << ", right: " << rightSum << ", ";
        root->val += rightSum;
        rightSum = root->val;
        // cout << "added, root: " << root->val << "\n";
        recursive(root->left, rightSum);
    }
};
// @lc code=end

