import java.util.Stack;

/*
 * @lc app=leetcode id=445 lang=java
 *
 * [445] Add Two Numbers II
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
// Solution2: Stack
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<Integer>();
        while (l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        }

        Stack<Integer> s2 = new Stack<Integer>();
        while (l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }

        ListNode current = new ListNode(0);
        int sum = 0;
        while(!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.pop();
            }
            System.out.print("out: \n" + sum );
            current.val = sum % 10;
            ListNode newHead = new ListNode(sum / 10);
            newHead.next = current;
            current = newHead;
            sum /= 10;
        }

        return current.val != 0 ? current : current.next;
    }
}

 // Solution1: recursion
// class Solution {
//     public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//         int n1 = length(l1); 
//         int n2 = length(l2);

//         ListNode head = new ListNode(1);
//         head.next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
//         if (head.next.val > 9) {
//             head.next.val %= 10;
//             return head;
//         }

//         return head.next;
//     }

//     public int length(ListNode head) {
//         int size = 0;
//         while (head != null) {
//             head = head.next;
//             size++;
//         }

//         return size;
//     }

//     public ListNode helper(ListNode l1, ListNode l2, int diff) {
//         if (l1 == null) {
//             return null;
//         }

//         ListNode current = (diff == 0) ? new ListNode(l1.val + l2.val) : new ListNode(l1.val);
//         ListNode post = (diff == 0) ? helper(l1.next, l2.next, 0) : helper(l1.next, l2, diff - 1);
//         if (post != null && post.val > 9) {
//             post.val %= 10;
//             current.val++;
//         }
//         current.next = post;
//         return current;
//     }
// }
// @lc code=end

