/*
 * @lc app=leetcode id=148 lang=java
 *
 * [148] Sort List
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
    public ListNode sortList(ListNode head) {
        return mergeSort2(head);
    }

    public ListNode mergeSort2(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        } 

        ListNode preslow = head;
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            preslow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        preslow.next = null;

        return merge2(mergeSort2(head), mergeSort2(slow));
    }

    public ListNode merge2(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                cur.next = l2;
                l2 = l2.next;
            } else {
                cur.next = l1;
                l1 = l1.next;
            }

            cur = cur.next;
        }

        if (l1 != null) {
            cur.next = l1;
        }

        if (l2 != null) {
            cur.next = l2;
        }

        return dummy.next;
    }

    // Use recursion to implement Divide-and-Conquer
    public ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode slow = head;
        ListNode fast = head;
        ListNode preslow = head;

        while (fast != null && fast.next != null) {
            preslow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // divide into sub lists, one's head is head
        // other's head is slow
        // and use preslow ti cut off the original list
        preslow.next = null;

        return merge(mergeSort(head), mergeSort(slow));
    }

    public ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } 

        if (l2 == null) {
            return l1;
        }

        if (l1.val > l2.val) {
            l2.next = merge(l2.next, l1);
            return l2;
        } else {
            l1.next = merge(l1.next, l2);
            return l1;
        }
    }
}
// @lc code=end

