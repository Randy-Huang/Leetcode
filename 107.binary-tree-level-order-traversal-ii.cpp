/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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

// Solution 1: use queue + stack
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        stack<vector<int>> st; // record level list
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front(); q.pop();
                level.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }

            st.push(level);
        }
        
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};

// Solution 1: use vector API
// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         if (!root) {
//             return {};
//         }

//         vector<vector<int>> res;
//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> level;

//             for (int i = 0; i < size; i++) {
//                 TreeNode* current = q.front(); q.pop();
//                 level.push_back(current->val);

//                 if (current->left) {
//                     q.push(current->left);
//                 }

//                 if (current->right) {
//                     q.push(current->right);
//                 }
//             }

//             res.insert(res.begin(), level);
//         }

//         return res;
//     }
// };
// @lc code=end

