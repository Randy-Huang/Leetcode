/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
// Solution 1: Recursion
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        recursive(root, 0);
        return res;
    }

    void recursive(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        if (res.size() == level) {
            // printf("level: %d, val: %d\n", level, root->val);
            // create level vector in the first node 
			// when we first tiem to get in the level
            res.push_back({});
        }
        res[level].push_back(root->val);

        recursive(root->left, level + 1);
        recursive(root->right, level + 1);
    }
};

// Solution 2: Iteration + queue
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;   
//         if (!root) {
//             return res;
//         }

//         queue<TreeNode*> queue;
//         queue.push(root);
        
//         while (!queue.empty()) {
//             int size = queue.size();
//             vector<int> level;

//             for (int i = 0; i < size; i++) {
//                 TreeNode* current = queue.front();
//                 queue.pop();

//                 level.push_back(current->val);

//                 if (current->left) {
//                     queue.push(current->left);
//                 }

//                 if (current->right) {
//                     queue.push(current->right);
//                 }
//             }

//             res.push_back(level);
//         }

//         return res;
//     }
// };
// @lc code=end

