/*
 * @lc app=leetcode id=19 lang=java
 *
 * [19] Remove Nth Node From End of List
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        return Solution1(head, n);
    }

    public ListNode Solution1(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        int size = 0;

        while (head != null) {
            size++;
            head = head.next;
        }

        head = dummy.next;
        int tailIndex = size - n;
        for (int i = 1; i < tailIndex; i++) {
            head = head.next;
        }

        // edge cases handler
        // remove the first element when size is equal to nth
        if (size == n) {
            dummy.next = dummy.next.next;
        } else {
            head.next = head.next.next;
        }

        return dummy.next;
    }

    public ListNode Solution2(ListNode head, int n) {
        ListNode fast, slow = head;
    }
}
// @lc code=end

