/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // example
        // 1 -> 2 -> 3 -> 4 -> 5 
        //           |         |   
        //           8 <- 7 <- 6   

        // slow: 1->2->3->4->5->6->7
        // fast: 1->3->5->7->3->5->7

        // we let 
        // 1->2->3 as a, 
        // 3->4->5->6->7 as b, 
        // and 7->8->3 as c
        // for the slow: the length is a + b
        // for the fast: the length is a + b + c + b

        // we have 2(a+b) = a + b + c + b
        // 2a + 2b = a + 2b + c
        // and then we have the equation: a = c

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // they meet each other at b point
                ListNode* current = head;

                while (current != slow) {
                    current = current->next;
                    slow = slow->next;
                }

                return current;
            }
        }

        return NULL;
    }
};
// @lc code=end

