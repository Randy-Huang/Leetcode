/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

// Solution 1: (iteration) https://leetcode.com/problems/path-sum-ii/discuss/1381104/c%2B%2B(4ms-96)-DFS-iterative-(with-comments)
// Solution 2: (recursion) https://www.cnblogs.com/grandyang/p/4042156.html
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        recursive(root, targetSum, path);
        return res;
    }

    // backtracing
    void recursive(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) {
            return;
        }

        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(path);
        } 

        recursive(root->left, targetSum - root->val, path);
        recursive(root->right, targetSum - root->val, path);

        path.pop_back();
    }

    vector<vector<int>> iterative(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        // tuple<TreeNode* node, int sum, int path>
        stack<tuple<TreeNode*, int, int>> st;
        vector<int> path;
        int sum = 0;

        TreeNode* current = root;

        // inorder traversal
        while (!st.empty() || current) {
            if (current) {
                // update sum and path result
                sum += current->val;
                path.push_back(current->val);
                //printf("current: %d, sum: %d, size: %d\n", current->val, sum, path.size());

                // check condition whether the result is compatitable the target
                if (sum == targetSum && !current->left && !current->right) {
                    res.push_back(path);
                }

                // and traversal
                st.push({current, sum, path.size()});
                current = current->left;
            } else {
                // pop the top node in stack and retore the node information
                tuple<TreeNode*, int, int> t = st.top(); st.pop();
                TreeNode* node = get<0>(t);
                sum = get<1>(t);
                path.resize(get<2>(t));

                current = node->right;
            }
        }

        return res;
    }
};
// @lc code=end

