/*
 * @lc app=leetcode id=160 lang=java
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

 // Reference: https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/easy/160.intersection-of-two-linked-lists
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        
        // There are two cases the two lists will meet at the intersectin
        // 1. at the tails, a = null && b = null
        // 2. at the intersection
        while (a != b) {
            if (a != null) {
                a = a.next;
            } else {
                a = headB;
            }

            if (b != null) {
                b = b.next;
            } else {
                b = headA;
            }
        }

        return a;
    }
}
// @lc code=end

