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
        return morris(root);
    }

    void printRightEdge(TreeNode* root, vector<int>& list) {
        // Only reverse the right edge of a tree
        TreeNode* tail = reverseRightEdge(root);
        TreeNode* current = tail;
        while (current) {
            printf("reverse func, val: %d\n", current->val);
            list.push_back(current->val);
            current = current->right;
        }

        // Restore the tree to the original
        reverseRightEdge(tail);
    }

    TreeNode* reverseRightEdge(TreeNode* root) {
        TreeNode* next = NULL;
        TreeNode* newRoot = NULL;

        while (root) {
            next = root->right;

            // break connection between root and root->right
            // and let newRoot be the root->right
            root->right = newRoot;
            newRoot = root;
            root = next;
        }

        return newRoot;
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

                    // When we visit this node in the second time
                    // just reversely print the right edge result
                    // of its left sub-tree 
                    printf("visit node: %d\n", current->val);
                    printRightEdge(current->left, list);
                }
            } 

            current = current->right;
        }

        // print reversely the right edge of a whole tree
        printf("Start final visit\n");
        printRightEdge(root, list);

        return list;
    }

    vector<int> postorder(TreeNode* root) {
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

