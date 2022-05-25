/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
// Solution 4: without hashmap by follow-up question using recursion
class Solution {
public:
vector<int> res;
    int mode = 0;
    int count = 1;

    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = NULL;
        inorder(root, pre);
        return res;
    }

    // We need to use call by reference for pre node TreeNode*& pre
    // and the coun
    // so that when we do pre == root and return back to the last function
    void inorder(TreeNode* root, TreeNode*& pre) {
        if (!root) {
            return;
        }
        //printf("cur: %p, val: %d\n", root, root->val);
        //printf("pre: %p, val: %d\n\n", pre, (pre) ? pre->val : -1);

        inorder(root->left, pre);
        if (pre) {
            //printf("compare cur: %d with pre: %d\n", root->val, pre->val);
            count = (root->val == pre->val) ? count + 1 : 1;
        }

        //printf("count: %d, mode:%d\n", count, mode);
        if (count >= mode) {
            if (count > mode) {
                //printf("clear\n");
                res.clear();
            }

            res.push_back(root->val);
            mode = count;
        }

        //printf("assign cur: %p to pre:%p\n", root, pre);
        pre = root;

        inorder(root->right, pre);
    }
};

// Solution 3: without hashmap by follow-up question using iteration
// class Solution {
// public:
//     vector<int> findMode(TreeNode* root) {
//          vector<int> res;
//         if (!root) {
//             return res;
//         }

//         stack<TreeNode*> stack;
//         TreeNode* current = root;

//         // use a previous node to update it when we want to update
//         TreeNode* previous = NULL;

//         int count = 1; // record a num what times it shows
//         int mode = 0;

//         while (!stack.empty() || current) {
//             if (current) {
//                 stack.push(current);
//                 current = current->left;
//             } else {
//                 TreeNode* node = stack.top(); stack.pop();
//                 if (previous) {
//                     count = (previous->val == node->val) ? count + 1 : 1;
//                 }
                    
//                 if (count >= mode) {
//                     if (count > mode) {
//                         // clear all the result of the list if 
//                         // we found a greater mode in BST
//                         res.clear();
//                     }

//                     res.push_back(node->val);
//                     mode = count;
//                 }

//                 previous = node;
//                 current = node->right;
//             }
//         }

//         return res;
//     }
// };

// Solution 2: basic solution using hashmap to record numbers + iteration
// class Solution {
// public:
//     vector<int> findMode(TreeNode* root) {
//         if (!root) {
//             return {};
//         }

//         unordered_map<int, int> map;
//         vector<int> res;

//         int mode = 0;

//         stack<TreeNode*> s;
//         TreeNode* current = root;

//         while (!s.empty() || current) {
//             if (current) {
//                 s.push(current);
//                 current = current->left;
//             } else {
//                 TreeNode* node = s.top(); s.pop();
//                 mode = max(mode, ++map[node->val]);
//                 current = node->right;
//             }
//         }

//         for (auto element : map) {
//             if (element.second == mode) {
//                 res.push_back(element.first);
//             }
//         }

//         return res;
//     }
// };

// Solution 1: basic solution using hashmap to record numbers + recursion
// class Solution {
// public:
//     unordered_map<int, int> map;
//     int mode;

//     vector<int> findMode(TreeNode* root) {
//         vector<int> res;
//         inorder(root);

//         for (auto num : map) {
//             if (num.second == mode) { // first is key, second is value
//                 res.push_back(num.first);
//             }
//         }
//         return res;
//     }

//     void inorder(TreeNode* root) {
//         if (!root) {
//             return;
//         }

//         inorder(root->left);
//         mode = max(mode, ++map[root->val]);
//         inorder(root->right);
//     }
// };
// @lc code=end

