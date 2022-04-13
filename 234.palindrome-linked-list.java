/*
 * @lc app=leetcode id=234 lang=java
 *
 * [234] Palindrome Linked List
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
    public boolean isPalindrome(ListNode head) {
        // if we don't use new head node to point at head
        // we cannot pass the case of [1, 2]
        ListNode slow = new ListNode(-1, head);
        ListNode fast = new ListNode(-1, head);

        // find the mid node
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // reverse the list from mid to the tail
        ListNode halfHead = reverse(slow.next);

        // start to compare values of two lists
        while (head != null && halfHead != null) {
            if (head.val != halfHead.val) {
                return false;
            }

            head = head.next;
            halfHead = halfHead.next;
        }

        return true;
    }

    public ListNode reverse(ListNode head) {
        ListNode newHead = null;
        
        while (head != null) {
            ListNode temp = head.next;
            head.next = newHead;
            newHead = head;
            head = temp;
        }

        return newHead;
    }
}
// @lc code=end

