import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=113 lang=java
 *
 * [113] Path Sum II
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
    private List<List<Integer>> results = new ArrayList<List<Integer>>();

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return results;
        }

        pathSum(root, new ArrayList<Integer>(), targetSum);
        return results;
    }

    public void pathSum(TreeNode root, List<Integer> subList, int targetSum) {
        subList.add(root.val);
        if (root.left == null && root.right == null) {
            if (targetSum == root.val) {
                results.add(new ArrayList<Integer>(subList));
                subList.remove(subList.size() - 1); // remove the last one from the sublist
                return;
            }
        }

        if (root.left != null) {
            pathSum(root.left, subList, targetSum - root.val);
        }

        if (root.right != null) {
            pathSum(root.right, subList, targetSum - root.val);
        }

        subList.remove(subList.size() - 1);
    }
}
// @lc code=end

