/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// Solution 1: https://www.cnblogs.com/grandyang/p/4296500.html
// Solution 2: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/2084068/c%2B%2B-easiest-code-with-explanation
class Solution {
public:
    // practice 12/21
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* recursive(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
        if (pStart > pEnd || iStart > iEnd) {
            return NULL;
        }

        int index;
        int size = inorder.size();
        for (index = iStart; index < size; index++) {
            if (inorder[index] == preorder[pStart]) {
                // match element
                break;
            }
        }

        TreeNode* node = new TreeNode(preorder[pStart]);

        int leftInStart = iStart;
        int leftInEnd = index - 1;
    
        int leftPreStart = pStart + 1;
        int leftPreEnd = leftPreStart + (leftInEnd - leftInStart);
        
        int rightInStart = index + 1;
        int rightInEnd = iEnd; 
        
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = pEnd;

        node->left = recursive(preorder, leftPreStart, leftPreEnd, inorder, leftInStart, leftInEnd);
        node->right = recursive(preorder, rightPreStart, rightPreEnd, inorder, rightInStart, rightInEnd);

        return node;
    }

    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     return recursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    // }

    // TreeNode* recursive(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
    //     if (pLeft > pRight || iLeft > iRight) {
    //         return NULL;
    //     }

    //     int index;
    //     for (index = 0; index < inorder.size(); index++) {
    //         if (preorder[pLeft] == inorder[index]) {
    //             break;
    //         }
    //     }

    //     TreeNode* root = new TreeNode(preorder[pLeft]);
    //     //printf("iLeft: %d, pLeft: %d, index: %d\n", iLeft, pLeft, index);

    //     // Set edges for for preorder and inorder
    //     int lInL = iLeft;
    //     int lInR = index - 1;
    //     int lPreL = pLeft + 1;
    //     // By equation: lPreR - lPreL = lInR - lInL
    //     // Be careful, we need to use new assignment of lInL and lInR
    //     int lPreR = lPreL + lInR - lInL;

    //     int rInL = index + 1;
    //     int rInR = iRight;
    //     int rPreL = lPreR + 1;
    //     int rPreR = pRight;

    //     root->left = recursive(preorder, lPreL, lPreR, inorder, lInL, lInR);
    //     root->right = recursive(preorder, rPreL, rPreR, inorder, rInL, rInR);
    //     return root;
    // }
};
// @lc code=end

