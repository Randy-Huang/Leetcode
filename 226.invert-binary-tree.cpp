/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        TreeNode* temp = dfs(root->left);
        root->left = dfs(root->right);
        root->right = temp;

        return root;
    }

    TreeNode* bfs(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* current = que.front(); que.pop();
                TreeNode* temp = current->left;
                current->left = current->right;
                current->right = temp;

                if (current->left) {
                    que.push(current->left);
                }

                if (current->right) {
                    que.push(current->right);
                }
            }
        }

        return root;
    }
};
// @lc code=end

