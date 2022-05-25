/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursive(root, targetSum);
    }

    bool recursive(TreeNode* root, int targetSum) {
         if (!root) {
            return false;
        }

        int sum = targetSum - root->val;
        if (sum == 0 && !root->left && !root->right) {
            return true;
        }

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }

    // Use queue + BFS
    //
    // I tried to use Stack + preorder traversal in this case
    // but some case like a node which has left and right node
    // we can't pop it from stack again when we traversal to its right
    // but we can use another stack to remember the path sum 
    // it needs to take another space to handle
    bool iterative(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        queue<pair<TreeNode*, int>> que;
        que.push({root, root->val});
        
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                pair<TreeNode*, int> currentPair = que.front(); que.pop();
                TreeNode* node = currentPair.first;
                int sum = currentPair.second;
                if (sum == targetSum && !node->left && !node->right) {
                    return true;
                }

                if (node->left) {
                    que.push({node->left, sum + node->left->val});
                }

                if (node->right) {
                    que.push({node->right, sum + node->right->val});
                }
            }
        }

        return false;
    }
};
// @lc code=end

