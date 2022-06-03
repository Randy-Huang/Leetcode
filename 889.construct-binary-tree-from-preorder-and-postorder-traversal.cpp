/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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

// Solution: https://www.cnblogs.com/grandyang/p/10909191.html
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return recursive(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* iterative(vector<int>& preorder, vector<int>& postorder) {

    }

    TreeNode* recursive(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int rootIndex;
        for (rootIndex = postStart; rootIndex <= postEnd; rootIndex++) {
            // preorder -> [root] [left subtree] [right subtree]
            // postorder -> [left subtree] [right substree] [root]
            // 
            // preorder -> [1] [2,4,5] [3,6,7]
            // postorder -> [4,5,2] [6,7,3] [root]
            //
            // In the left sub-tree, we can notice that the next node of the root
            // in preorder is the final node In the left sub-tree in postorder
            // we can use the both order to get the lengh of the sub-tree
            // to set the start and end for each sub-tree  
            if (preorder[preStart + 1] == postorder[rootIndex]) {
                break;
            }
        }

        int lPostS = postStart;
        int lPostE = rootIndex;
        int lPreS = preStart + 1; // the start index
        int lPreE = lPreS + (lPostE - lPostS); // the length of sub tree of lPostE - lPostS

        int rPreS = lPreE + 1;
        int rPreE = preEnd;
        int rPostS = rootIndex + 1;
        int rPostE = postEnd - 1; // remember don't include root node

        root->left = recursive(preorder, lPreS, lPreE, postorder, lPostS, lPostE);
        root->right = recursive(preorder, rPreS, rPreE, postorder, rPostS, rPostE);
        return root;
    }
};
// @lc code=end

