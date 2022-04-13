/*
 * @lc app=leetcode id=98 lang=java
 *
 * [98] Validate Binary Search Tree
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
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    // we need to consider edge cases of 2^31 and -2^31
    // and we can use long type to solve these cases
    public boolean isValidBST(TreeNode root, long lastMin, long lastMax) {
        if (root == null) {
            return true;
        }

        if (lastMin >= root.val || root.val >= lastMax) {
            return false;
        }
        
        return isValidBST(root.left, lastMin, root.val) && isValidBST(root.right, root.val, lastMax);
    }
}
// @lc code=end

