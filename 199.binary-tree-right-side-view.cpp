/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodeQueue.front(); nodeQueue.pop();
                if (i == size - 1) {
                    res.push_back(node->val);
                }

                if (node->left) {
                    nodeQueue.push(node->left);
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
        }

        return res;
    }
};
// @lc code=end

