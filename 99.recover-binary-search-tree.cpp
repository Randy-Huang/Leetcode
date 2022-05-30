/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        morris(root);
    }

    void morris(TreeNode* root) {
        TreeNode* current = root;
        TreeNode* mostRight = NULL;

        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        while (current) {
            mostRight = current->left;
            if (mostRight) {
                while (mostRight->right && mostRight->right != current) {
                    mostRight = mostRight->right;
                }

                if (!mostRight->right) {
                    mostRight->right = current;
                    current = current->left;
                    continue;
                } else {
                    mostRight->right = NULL;
                }
            } 

            // In BST, pre val is always less than or equal to the current
            // so if there exist two nodes that are need to swap correctly
            // let first to record pre node
            // and second to record the current node
            if (pre && pre->val > current->val) {
                //printf("current val: %d, pre val: %d\n", current->val, pre->val);
                if (!first) {
                    first = pre;
                }
                second = current;
            }

            pre = current;
            current = current->right;
        }

        swap(first->val, second->val);
    }
};
// @lc code=end

