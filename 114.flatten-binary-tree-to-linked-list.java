import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=114 lang=java
 *
 * [114] Flatten Binary Tree to Linked List
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

 // Reference: https://www.cnblogs.com/grandyang/p/4293853.html
class Solution {
    public void flatten(TreeNode root) {
        preorderIterate(root);
    }

    // Solution 1: recursion + preorder traversa
    // traversal to the left node of its parent node
    // let parent node disconnect the right node and 
    // connect to the left node
    public void recursive(TreeNode root) {
        if (root == null) {
            return;
        }

        // traversal child nodes
        recursive(root.left);
        recursive(root.right);

        // handle and re-connect child nodes
        TreeNode tempRight = root.right;
        root.right = root.left;
        root.left = null;

        // connect the origin right node to the end of the 
        // right branch
        while (root.right != null) {
            root = root.right;
        }
        root.right = tempRight;
    }

    // Solution 2: iteration
    public void iterator(TreeNode root) {
        TreeNode current = root;

        // only iterate right side of a tree
        while (current != null) {
            if (current.left != null) {
                // Restore the root of the left
                TreeNode tempLeft = current.left;

                // now we need to iterate at the end of
                // the left sub tree's right branch 
                // and connect to the root of the right sub tree
                while (tempLeft.right != null) {
                    tempLeft = tempLeft.right;
                }

                // put the right sub tree to the 
                // end of the left sub tree
                tempLeft.right = current.right;

                // let the left sub tree to the right part
                current.right = current.left;
                current.left = null;
            }
            current = current.right;
        }
    }

    // Solution 3: Iteration + preorder
    public void preorderIterate(TreeNode root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            if (current.left != null) {
                TreeNode tempLeft = current.left;

                // now we need to iterate at the end of
                // the current'left sub tree's right branch 
                // and connect to the current of the right sub tree
                while (tempLeft.right != null) {
                    tempLeft = tempLeft.right;
                }

                tempLeft.right = current.right;
                current.right = current.left;
                current.left = null;
            }

            if (current.right != null) {
                stack.push(current.right);
            }
        }
    }
}
// @lc code=end

