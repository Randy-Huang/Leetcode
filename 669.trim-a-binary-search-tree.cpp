/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
// Solution: Recursion
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // remain number range from low to high
        return recursive(root, low, high);
    }

    TreeNode* recursive(TreeNode* root, int low, int high) {
        if (!root) {
            return nullptr;
        }

        // trim node
        // 1. if current root val is greater than high boundry
        // we can say its children are both greater than 
        // the parent node of the root node
        if (root->val > high) {
            return recursive(root->left, low, high);
        }

        // 2. if current root val is less than low boundry
        // we can say its children are both less than 
        // the parent node of the root node
        if (root->val < low) {
            return recursive(root->right, low, high);
        }

        // remina node
        // low <= root->val <= high
        root->left = recursive(root->left, low, high);
        root->right = recursive(root->right, low, high);
        return root;
    }
};
// @lc code=end

