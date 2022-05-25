/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        stack<TreeNode*> st;
        TreeNode* current = root;

        int count = 0;
        while (!st.empty() || current) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* node = st.top(); st.pop();
                count++;
                if (count == k) {
                    return node->val;
                }

                current = node->right;
            }
        }

        return 0;
    }
};
// @lc code=end

