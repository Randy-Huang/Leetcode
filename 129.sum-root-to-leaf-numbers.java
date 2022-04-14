/*
 * @lc app=leetcode id=129 lang=java
 *
 * [129] Sum Root to Leaf Numbers
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
    int total = 0;

    public int sumNumbers(TreeNode root) {
        sumNumbersHelper(root, 0);
        return total;
    }

    public void sumNumbersHelper(TreeNode root, int pathSum) {
        if (root == null) {
            return;
        }

        pathSum = root.val + (pathSum * 10);

        if (root.left == null && root.right == null) {
            total += pathSum;
            return;
        }

        sumNumbersHelper(root.left, pathSum);
        sumNumbersHelper(root.right, pathSum);
    }
}
// @lc code=end

