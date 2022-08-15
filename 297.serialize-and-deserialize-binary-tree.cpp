/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Reference: https://www.cnblogs.com/grandyang/p/4913869.html
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode = "";
        if (root) {
            dfs(root, encode);
        }

        return encode;
    }

    void dfs(TreeNode* root, string& encode) {
        if (!root) {
            encode.append("# ");
            return;
        }

        encode.append(to_string(root->val)).append(" ");
        dfs(root->left, encode);
        dfs(root->right, encode);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        printf("deserialize\n");
        istringstream in(data);
        return recursive(in);
    }

    TreeNode* recursive(istringstream& decode) {
        if (!decode) {
            return NULL;
        }

        string val;
        decode >> val;
        if (val == "#") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = recursive(decode);
        root->right = recursive(decode);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

