/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
// Solution: https://www.cnblogs.com/grandyang/p/4296193.html
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursive(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* recursive(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd) {
        if (iStart > iEnd || pStart > pEnd) {
            return NULL;
        }

        int rootIndex;
        for (rootIndex = iStart; rootIndex < inorder.size(); rootIndex++) {
            if (inorder[rootIndex] == postorder[pEnd]) {
                break;
            }
        }

        TreeNode* root = new TreeNode(postorder[pEnd]);

        // set edges start from right to the left
        int rInS = rootIndex + 1;
        int rInE = iEnd;
        int rPoE = pEnd - 1;
        int rPoS = rPoE - rInE + rInS; // rPoE - rPoS = rInE - rInS

        int lInS = iStart;
        int lInE = rootIndex - 1;
        int lPoS = pStart;
        int lPoE = rPoS - 1;

        root->left = recursive(inorder, lInS, lInE, postorder, lPoS, lPoE);
        root->right = recursive(inorder, rInS, rInE, postorder, rPoS, rPoE);

        return root;
    }
};
// @lc code=end

