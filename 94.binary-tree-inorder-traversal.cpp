/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        return morris(root);
    }

    vector<int> morris(TreeNode* root) {
        vector<int> list;

        TreeNode* current = root;
        TreeNode* mostRight = NULL;

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

            // 1. if current->left == null, we only visit this node once and print it
            // 2. if current->left != null, we will visit it twice, and print this node
            //    in the second time 
            list.push_back(current->val);
            current = current->right;
        }

        return list;
    }

    vector<int> inorder(TreeNode* root) {
        vector<int> list;
        stack<TreeNode*> stack;

        TreeNode* current = root;

        while(current || !stack.empty()) {
            if (current) {
                stack.push(current);
                current = current->left;
            } else {
                TreeNode* node = stack.top();
                stack.pop();
                list.push_back(node->val);
                current = node->right;
            }
        }
        
        return list;
    }
};
// @lc code=end

