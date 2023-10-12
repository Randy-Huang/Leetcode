/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
private:
    unordered_map<int, vector<TreeNode*>> cache;

public:
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        if (n % 2 == 0) 
        {
            return {};
        }

        if (n == 1) 
        {
            return { new TreeNode(0) };
        }

        if (cache.count(n)) 
        {
            return cache[n];
        }

        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2) 
        {

            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - 1 - i);

            for (auto l : left) 
            {
                for (auto r : right) 
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            } 
        }

        cache[n] = res;
        return res;
    }
};
// @lc code=end

