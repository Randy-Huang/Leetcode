import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=226 lang=java
 *
 * [226] Invert Binary Tree
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
    public TreeNode invertTree(TreeNode root) {
        return iterative(root);
    }

    public TreeNode recursive(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode temp = recursive(root.left);
        root.left = recursive(root.right);
        root.right = temp;
        return root;
    }

    public TreeNode iterative(TreeNode root) {
        if (root == null) {
            return null;
        }

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            TreeNode currentLeft = current.left;

            // add nodes of the current node
            if (current.left != null) {
                stack.push(current.left);
            }

            if (current.right != null) {
                stack.push(current.right);
            }

            current.left = current.right;
            current.right = currentLeft;
        }

        return root;
    }
}
// @lc code=end

