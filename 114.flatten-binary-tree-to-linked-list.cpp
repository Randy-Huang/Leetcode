/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
// Reference: https://www.cnblogs.com/grandyang/p/4293853.html
class Solution {
public:
    void flatten(TreeNode* root) {
        iterate(root);
    }

    // Solution 1: recursion + preorder traversal
    // traversal to the left node of its parent node
    // let parent node disconnect the right node and 
    // connect to the left node
    void recursive(TreeNode* root) {
        if (!root) {
            return;
        }

        // traversal child nodes
        recursive(root->left);
        recursive(root->right);

        // handle and re-connect child nodes
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;

        // connect the origin right node to the end of the 
        // right branch
        while (root->right) {
            root = root->right;
        }
        root->right = tmp;
    }

    // Solution 2: iteration 
    void iterate(TreeNode* root) {
        TreeNode* current = root;
        
        // only iterate right side of a left sub-tree
        while (current) {
            if (current->left) {
                // Restore the left node of the current node
                TreeNode* tmpMostRight = current->left;

                // now we need to iterate at the end of
                // the left sub tree's right branch 
                // and connect to the root of the right sub tree
                while (tmpMostRight->right) {
                    tmpMostRight = tmpMostRight->right;
                }

                // link the right sub tree of the current to the 
                // end of its left sub tree
                // example: an original tree
                //                 1
                //                / \
                //               2   5
                //              / \   \
                //             3   4   6
                tmpMostRight->right = current->right;
                // and it becomes: 
                // the 4's right is 5, and 5's left is still null
                //                  1
                //                /   \
                //               2     5
                //              / \    / \
                //             3   4  /   6
                //                  \/


                // put the left sub tree to the right part
                current->right = current->left;
                current->left = NULL;
                // and it becomes:
                //                 1
                //                  \
                //                   2
                //                  / \
                //                 3   4
                //                      \
                //                       5
                //                        \
                //                         6
            }   

            // Finish putting the left side sub tree of the current node
            // to the right side sub tree, now because left is null
            // so we iterate the right node handling the same procedure
            current = current->right;
        }
    }
};
// @lc code=end

