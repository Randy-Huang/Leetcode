/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        stack<TreeNode*> stack;

        TreeNode* current = root;

        while (!stack.empty() || current) {
            if (current) { // traversal to the left
                stack.push(current);
                current = current->left;
            } else { // traversal to the right
                TreeNode* right = stack.top()->right;
                if (!right) {
                    TreeNode* record = stack.top();
                    stack.pop();
                    list.push_back(record->val);

                    while (!stack.empty() && record == stack.top()->right) {
                        record = stack.top();
                        stack.pop();
                        list.push_back(record->val);
                    }
                } else {
                    current = right;
                }
            }
        }

        return list;
    }
};
// @lc code=end

