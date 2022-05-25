/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }

        stack<pair<TreeNode*, int>> st;
        TreeNode* current = root;

        int sum = 0;
        while (!st.empty() || current) {
            if (current) {
                sum = sum * 10 + current->val;

                if (!current->left && !current->right) {
                    res += sum;
                }

                st.push({current, sum});
                current = current->left;
            } else {
                pair<TreeNode*, int> p = st.top(); st.pop();
                TreeNode* node = p.first;
                sum = p.second;

                current = node->right;
            }
        }

        return res;
    }
};
// @lc code=end

