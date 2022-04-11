import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=145 lang=java
 *
 * [145] Binary Tree Postorder Traversal
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();

        TreeNode current = root;
        while (!stack.isEmpty() || current != null) {
            if (current != null) {
                stack.push(current);
                current = current.left;
            } else {
                // Check the right of a top node
                TreeNode node = stack.peek().right;
                if (node != null) {
                    current = node;
                } else { // the right node of a top node is null
                    node = stack.pop();
                    list.add(node.val);

                    // Check whether right branch of node is existed continuously
                    // We use a while loop to check a relations between
                    // the root node that has the right node and prevent
                    // the loop for our here
                    // for example, list [1,null,2,3], there're a loop happens
                    // in 1 and 2 because 2 is 1's right node 
                    while (!stack.isEmpty() && (node == stack.peek().right)) {
                        node = stack.pop();
                        list.add(node.val);
                    }
                }
            }
        }

        return list;
    }
}
// @lc code=end

