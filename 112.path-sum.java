import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=112 lang=java
 *
 * [112] Path Sum
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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return recursion(root, targetSum);
    }

    public boolean recursion(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }

        int sum = targetSum - root.val;

        if (sum == 0 && root.left == null && root.right == null) {
            return true;
        }

        return recursion(root.left, sum) || recursion(root.right, sum);
    }

    public boolean traversal(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            if (current.left == null && current.right == null) {
                if (targetSum == current.val) {
                    return true;
                }
            }

            if (current.left != null) {
                current.left.val += current.val;
                stack.push(current.left);
            }

            if (current.right != null) {
                current.right.val += current.val;
                stack.push(current.right);
            }
        }

        return false;
    }
}
// @lc code=end

