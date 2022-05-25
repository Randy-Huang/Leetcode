/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

// Reference 1: https://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86
// 
// Reference 2: https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better
//
// Reference 3: https://zhuanlan.zhihu.com/p/100531135
//
// Reference 4: https://www.cnblogs.com/grandyang/p/4045660.html
//
// Solution 1: Recursion (bad case, not optimized)
// Time: O(NlogN) using "Master Theory"
//
// T(n) = aT(n/b) + f(n^d)
//
// Time complexity for depth:
// T(n) = 2T(n/2) + O(1)
// a = 2, b =2, d = 0
// a > b^d, therefore, O(n^(logba)) = O(n)
//
// T(n) = 2T(n/2) + O(n)
// a = 2, b =2, d = 1
// a = b^d, therefore, O((n^d)*logn) = O(nlogn)
// 
// Space: O(H)
//
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        bool balanced = abs(left - right) <= 1;

        return balanced && isBalanced(root->left) && isBalanced(root->right);
    }

    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return 1 + max(left, right);
    }
};

// Solution 2: Recursion reducing duplicated the calculation of depth and balanced
// Time: O(N) using "Master Theory"
//
// T(n) = aT(n/b) + f(n^d)
// a = 2, b = 2, d = 0
// a > b^d, therefore O(n^(logba)) = O(n)
//
// Space: O(H)
//
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (getHeight(root) == -1) {
//             return false;
//         }

//         return true;
//     }

//     int getHeight(TreeNode* root) {
//         if (!root) {
//             return 0;
//         }

//         int left = getHeight(root->left);
//         if (left == -1) {
//             return -1;
//         }

//         int right = getHeight(root->right);
//         if (right == -1) {
//             return -1;
//         }

//         int diff = abs(left - right);
//         if (diff > 1) {
//             return -1;
//         }

//         return 1 + max(left, right);
//     }
// };
// @lc code=end

