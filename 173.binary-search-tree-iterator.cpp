/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    int INVALID = -1;
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        if (st.empty()) {
            return INVALID;
        }

        TreeNode* current = st.top(); st.pop();
        int res = current->val;

        if (current->right) {
            current = current->right;
            while (current) {
                st.push(current);
                current = current->left;  
            }
        }

        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

