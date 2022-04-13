/*
 * @lc app=leetcode id=1721 lang=java
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if (head == null) {
            return null;
        }

        ListNode current = head;
        ListNode oppsite = head;
        ListNode end = head;

        for (int i = 1; i < k; i++) {
            current = current.next;
            end = end.next;
        }

        while (end != null && end.next != null) {
            end = end.next;
            oppsite = oppsite.next;
        }

        int tmp = current.val;
        current.val = oppsite.val;
        oppsite.val = tmp;

        return head;
    }
}
// @lc code=end

