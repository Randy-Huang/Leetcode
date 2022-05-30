/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        return morris(root);
    }

    vector<int> morris(TreeNode* root) {
        vector<int> list;

        TreeNode* current = root;
        TreeNode* mostRight = NULL;

        while (current) {
            mostRight = current->left;
            if (mostRight) { // has left sub-tree
                while (mostRight->right && mostRight->right != current) {
                    mostRight = mostRight->right;
                }

                if (!mostRight->right) { // the first time to visit this node
                    //printf("1 Val: %d\n", current->val);
                    list.push_back(current->val);
                    mostRight->right = current;
                    current = current->left;
                    continue;
                } else { // mostRight == cur
                    mostRight->right = NULL;
                }
            }
            else { // has no left sub-tree, only visit this node once
                //printf("2 Val: %d\n", current->val);
                list.push_back(current->val);
            }

            current = current->right;
        }

        return list;
    }

    vector<int> preorder(TreeNode* root) {
        vector<int> list;
        stack<TreeNode*> stack;

        TreeNode* current = root;
        while (current || !stack.empty()) {
            if (current) {
                list.push_back(current->val);
                stack.push(current);
                current = current->left;
            } else {
                TreeNode* node = stack.top();
                stack.pop();
                current = node->right;
            }
        }

        return list;
    }
};
// @lc code=end

