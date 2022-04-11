import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=102 lang=java
 *
 * [102] Binary Tree Level Order Traversal
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        if (root == null) {
            return results;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);

        // Outter loop handle level order
        while (!queue.isEmpty()) {
            List<Integer> levelList = new ArrayList<Integer>();
            int size = queue.size();

            // Outter loop handle all the nodes in the same level
            // Start traverse nodes from the left to the right in the same level
            for (int i = 0; i < size; i++) {
                TreeNode current = queue.poll();
                levelList.add(current.val);

                if (current.left != null) {
                    queue.add(current.left);
                } 

                if (current.right != null) {
                    queue.add(current.right);
                }
            }
            results.add(levelList);
        }

        return results;
    }
}
// @lc code=end

