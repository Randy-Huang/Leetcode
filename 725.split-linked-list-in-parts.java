import java.util.Currency;

/*
 * @lc app=leetcode id=725 lang=java
 *
 * [725] Split Linked List in Parts
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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] results = new ListNode[k];

        ListNode current = head;
        int size = 0;
        while (current != null) {
            current = current.next;
            size++;
        }

        int average = size / k;
        int remainder = size % k;
        for (int i = 0; i < k; i++) {
            if (head == null) {
                break;
            }

            results[i] = head;
            for (int j = 1; j < average + (remainder > i ? 1 : 0) ; j++) {
                head = head.next;
            }

            ListNode nextHead = head.next;
            head.next = null;
            head = nextHead;
        }

        return results;
    }
}
// @lc code=end

