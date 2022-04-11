/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left == null) {
            return maxDepth(root.right) + 1;
        }

        if (root.right == null) {
            return maxDepth(root.left) + 1;
        }

        return Math.max(maxDepth(root.right), maxDepth(root.left)) + 1;
    }
}

// class Solution {
//     int max = 0;
//     int depth = 0;

//     public int maxDepth(TreeNode root) {
//         traverse(root);
//         return max;
//     }

//     public void traverse(TreeNode root) {
//         if (root == null) {
//             max = Math.max(max, depth);
//             return;
//         }

//         depth++;
//         maxDepth(root.left);
//         maxDepth(root.right);
//         depth--;
//     }
// }
// @lc code=end

