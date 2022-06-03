/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return recursive(preorder, 0, preorder.size() - 1);
    }

    TreeNode* recursive(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[start]);
        if (start == end) {
            return root;
        }

        int rightIndex;
        for (rightIndex = start + 1; rightIndex <= end; rightIndex++) {
            if (root->val < preorder[rightIndex]) {
                break;
            }
        }

        int lStart = start + 1;
        int lEnd = rightIndex - 1;
        int rStart = rightIndex;
        int rEnd = end;

        root->left = recursive(preorder, lStart, lEnd);
        root->right = recursive(preorder, rStart, rEnd);

        return root;
    }
};
// @lc code=end

