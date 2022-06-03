/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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

// Reference: https://leetcode.cn/problems/count-complete-tree-nodes/solution/c-san-chong-fang-fa-jie-jue-wan-quan-er-cha-shu-de/
class Solution {
public:
    int countNodes(TreeNode* root) {
        return iterativeFinalLevel(root);
    }

    // Solution 1: simplified recursive by the character of complete binary tree
    // We just can make sure the depth of the left sub-tree 
    // is equal to or greater than the right sub-tree
    // 
    // 1. First of all, because the problem has already ensured
    // that the tree is a complete tree, according to this condition
    // we just iterate the left side tree to get the height 
    // we don't need to iterate the right side when we want to get hight
    //
    // Time complexity for height:
    // T(n) = T(n/2) + O(1)
    // a = 1, b = 2, d = 0
    // a = b^d, therefore, O((n^d)*logn) = O(logn)
    //
    // T(n) = 2T(n/2) + O(logn)
    // a = 2, b = 2, 0 < d < 1 because n^d = logn
    // a > b^d, therefore, O(n^(logba)) = O(n)
    // 
    // Space: O(H)
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    // We know that tree is ensured that a complete tree
    // if the height of the left sub-tree is equal to 
    // the right, which means the left sub-tree is
    // a complete binary tree for the root node 1
    //           1
    //         /   \
    //        2     3
    //       / \   /
    //      4   5 6
    //
    // if the height of the left sub-tree is greater than 
    // the right, which means the right sub-tree is
    // a complete binary tree
    //           1
    //         /   \
    //        2     3
    //       / \   / \
    //      4   5 6   7
    //     /
    //    8
    //
    int recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getLeftHeight(root->right);

        // use the formula: 2^d - 1 to compute the nodes
        // in a tree when it is a perfect binary tree
        // => (1 << height) - 1 for get nodes when a tree 
        // has d height
        // 
        // Be careful, when we return nodes, we've mentioned
        // the total nodes is (1 << height) - 1, but we also 
        // add the current it self and then return 
        // so (1 << height) - 1 + 1 = (1 << height)
        if (leftHeight == rightHeight) {
            return recursive(root->right) + (1 << leftHeight);
        } else { 
            return recursive(root->left) + (1 << rightHeight);
        }
    }

    // Solution 2: iterative + binary search
    // For the complete binary tree, we assume that tree
    // has d depth, and for the d-1 except for the last level
    // this tree is a perfect binary tree, it has 2^(d-1) - 1 nodes
    // so we just focus on the final level and use binary search
    // to locate the length (the amount of nodes)
    int iterativeFinalLevel(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int depth = getLeftDepth(root);
        int preDepth = depth - 1;

        // we are trying to find the nodes of the final level (or depth)
        // and for the depth d, this layer has nodes up to 2^(d-1)
        // and we also use binary search to locate the find the final node
        // which between [start, end] from the left to the right
        // we use the function isExist() to check the divided line
        //                        
        //   |  1  |  1  |  1  |  1  |  0  |  0  |
        //    start        mid               end
        //
        int start = 1, end = (1 << preDepth);
        while (start <= end) {
            // the mid is the index that use to find the node
            // between [1, 2^(d-1)]
            // if the index of the node exists, it must exist
            // in the right side of the index, otherwise,
            // in the left side 
            int mid = start + ((end - start) >> 1);
            // printf("depth: %d, prev depth: %d, mid: %d, end: %d\n", depth, preDepth, mid, end);
            if (isExist(root, mid, preDepth)) {
                start = mid + 1;
            } else {
                end = mid -1;
            }
        }

        // ((1 << preDepth) -1) is the total nodes of the d-1 depth of a tree
        // (start - 1) is the nodes of the final level
        return ((1 << preDepth) -1) + (start - 1);
    }

    // root: the binary tree's top node
    //
    // index: use this index to judge whether the index of the node 
    // exists in the final level.
    // the range is [1, 2^(d-1)] = [1, 2^(preDepth)]
    //
    // preDepth: the previous level's depth of a tree
    // for the last second level, it has 2^(d-1) nodes
    //
    // We use the function to judge the index  
    // in the final level whether the node exists
    bool isExist(TreeNode* root, int index, int preDepth) {
        TreeNode* current = root;
        while (preDepth) {
            // the final layer mid line
            // ((1 << preDepth) >> 1) == (2 ^ preDepth) / 2
            // because the final level has 2 ^ preDepth nodes
            int mid = ((1 << preDepth) >> 1);
            // printf("mid: %d, index: %d, node: %d\n", mid, index, current->val);
            if (index > mid) {
                // index > mid which means the target is in the
                // right side of the tree. we need do index -= mid
                // because we'll reduce mid in the next time
                // in the left part, we don't need to do that 
                // because mid starts from the left, but if 
                // in the right side, it needs to minus value mid
                // for the next time
                current = current->right;
                index -= mid;
            } else {
                current = current->left;
            }

            // Because we've focused the node of the index 
            // in the one side branch of the root, which means
            // the depth will reduce one level
            preDepth--;
        }

        return current != NULL;
    }

    int getLeftDepth(TreeNode* root) {
        int depth = 0;
        while (root) {
            depth++;
            root = root->left;
        }

        return depth;
    }
};
// @lc code=end

