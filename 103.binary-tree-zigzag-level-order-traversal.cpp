/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        bool inverse = false;
        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodeQueue.front(); nodeQueue.pop();
                if (inverse) {
                    level.insert(level.begin(), node->val);
                } else {
                    level.push_back(node->val);
                }

                if (node->left) {
                    nodeQueue.push(node->left);        
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }

            inverse = !inverse;
            res.push_back(level);
        }

        return res;
    }
};
// @lc code=end

