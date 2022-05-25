/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
// Reference: https://leetcode.com/problems/validate-binary-search-tree/discuss/2066650/3-Approaches-Iterative-and-Recursive-C%2B%2B
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // return recursive(root, LONG_MIN, LONG_MAX);
        return iterative(root);
    }

    bool iterative(TreeNode* root) {
        if (!root) {
            return true;
        }

        stack<TreeNode*> st;
        TreeNode* current = root;

        // previous node we pop out of the stack
        // for the BST, we only make sure if the previous node
        // is great than or equel to current, 
        // the BST is not valid
        TreeNode* previous = NULL;

        while (!st.empty() || current) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* node = st.top(); st.pop();
                if (previous && previous->val >= node->val) {
                    return false;
                }

                previous = node;
                current = node->right;
            }
        }

        return true;
    }

    bool recursive(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }

        // if we use int max or min, we can not handle edge cases 
        // of max and min here
        if (min >= root->val || root->val >= max) {
            return false;
        }

        return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
    }
};
// @lc code=end

