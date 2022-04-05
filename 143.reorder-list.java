import javax.management.ListenerNotFoundException;

/*
 * @lc app=leetcode id=143 lang=java
 *
 * [143] Reorder List
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
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        ListNode slow = head;
        ListNode fast = head;
        
        // divide the list into 2 sbu-lists
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // remember we need to wet slow to be null 
        // which means cut off from the second list
        ListNode mid = slow.next;
        slow.next = null;

        ListNode subHead = rotateList(mid);

        // merge two lists
        while (head != null && subHead != null) {
            ListNode temp = head.next;
            head.next = subHead;
            subHead = subHead.next;
            head.next.next = temp;
            head = temp;
        }
    }

    public ListNode rotateList(ListNode head) {
        ListNode newHead = null;

        while (head != null) {
            ListNode next = head.next;
            head.next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
}
// @lc code=end

