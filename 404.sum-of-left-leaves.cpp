/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        // int sum = 0;
        // recursive(root, false, sum);
        // return sum;

        return iterativeBFS(root);
    }

    void recursive(TreeNode* root, bool isLeft, int& sum) {
        if (!root) {
            return;
        }

        // The left leave-node must have no left and right nodes
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
        }

        recursive(root->left, true, sum);
        recursive(root->right, false, sum);
    }

    int iterative(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        stack<TreeNode*> stack;
        TreeNode* current = root;

        while (!stack.empty() || current) {
            if (current) {
                stack.push(current);     
                current = current->left;
                if (current && !current->left && !current->right) {
                    sum += current->val;
                }
            } else {
                TreeNode* node = stack.top(); stack.pop();         
                current = node->right;
            }
        }

        return sum;
    }

    int iterativeBFS(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodeQueue.front(); nodeQueue.pop();

                if (node->left) {
                    nodeQueue.push(node->left);
                    if (isLeaf(node->left)) {
                        sum += node->left->val;
                    }
                }

                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
        }

        return sum;
    }

    bool isLeaf(TreeNode* node) {
        return (node && !node->left && !node->right);
    }
};
// @lc code=end

