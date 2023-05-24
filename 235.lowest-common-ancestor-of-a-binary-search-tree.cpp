/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Reference: https://desolve.medium.com/%E5%BE%9Eleetcode%E5%AD%B8%E6%BC%94%E7%AE%97%E6%B3%95-51-bst-4-94cd8fe956ac

// Time/Space
// worst case: O(N)/O(N) if BST is skewed
// avg case: O(logN)/O(logN) if BST is balanced
// if we use iteration, then space is O(1) 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        
        int maxVal = max(p->val, q->val);
        int minVal = maxVal == p->val ? q->val : p->val;
        if (minVal < root->val && root->val < maxVal) {
            return root;
        }

        if (root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }
};
// @lc code=end

