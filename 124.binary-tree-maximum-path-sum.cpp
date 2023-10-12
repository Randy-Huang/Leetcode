/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

// Reference: https://www.cnblogs.com/grandyang/p/4280120.html
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int res = INT_MIN;
//         recursive(root, res);
//         return res;
//     }

//     // We can see the tree's path sum is 7->11->4->13 as below:
//     //     4
//     //    / \
//     //   11  13
//     //   / \
//     //  7   2
//     //
//     // But how do we use recursive to calculate the max path sum?
//     // For node 7, if 7 is root also is a leaf, the path is 7
//     // For node 11, we are backtracing from 7 to node 11, 
//     // the max path sum is 7->11->2. 
//     // For node 4, we are backtracing from 11 to 4,
//     // we need to be careful, when 4 is root node
//     // node 11 only have to choose the left or the right
//     // that is the max value, which means:
//     // 7 -> 11 -> 4 -> 13 or 2 -> 11 -> 4 -> 13

//     int recursive(TreeNode* root, int& maxSum) {
//         if (!root) {
//             return 0;
//         }

//         int left = max(recursive(root->left, maxSum), 0);
//         int right = max(recursive(root->right, maxSum), 0);

//         // for the global sum, we use maxSum to record the value
//         // to compare different pathes
//         maxSum = max(maxSum, (left + right + root->val));

//         // return only one branch path sum and its own val
//         // to its parent node
//         return max(left, right) + root->val;
//     }
// };

// 2023.04.25
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        recursive(root, res);
        return res;
    }

    int recursive(TreeNode* root, int& maxSum) {
        if (!root) {
            return 0;
        }

        int leftSum = max(0, recursive(root->left, maxSum));
        int rightSum = max(0, recursive(root->right, maxSum));

        maxSum = max(maxSum, (root->val + leftSum + rightSum));

        return max(leftSum, rightSum) + root->val;
    }
};
// @lc code=end

