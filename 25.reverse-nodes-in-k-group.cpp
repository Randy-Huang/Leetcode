/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return recursive(head, k);
    }

    ListNode* recursive(ListNode* head, int k) {
        ListNode* current = head; // use head to record the start point of the sub group

        for (int i = 0; i < k; i++) {
            if (!current) {
                return head;
            }

            current = current->next; // current node will be the start point of the next sub group
        }

        // after reversing, head will be the new tail with same node
        ListNode* newHead = reverseRec(head, current);
        head->next = recursive(current, k);

        return newHead;
    }

    // return the new head of the group list
    ListNode* reverseRec(ListNode* head, ListNode* tail) {
        ListNode* pre = NULL;
        ListNode* current = head;

        while (current != tail) {
            ListNode* tmp = current->next;
            current->next = pre;
            pre = current;
            current = tmp;
        }

        return pre;
    }

    ListNode* iterative(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* current = head;

        int step = 1;
        while (current) {
            // origin
            // -1 -> 1 -> 2 -> 3 -> 4 -> 5
            //  |              |    |
            // pre            cur  next
            //
            // after reverse
            // -1 -> 3 -> 2 -> 1 -> 4 -> 5
            //       |         |    |
            //      cur       pre  next

            if (step % k == 0) {
                pre = reverse(pre, current->next);
                current = pre->next;
            } else {
                current = current->next;
            }

            step++;
        }

        return dummy->next;
    }

    // return the tail
    ListNode* reverse(ListNode* pre, ListNode* nextHead) {
        ListNode* first = pre->next;
        ListNode* second = first->next;
        
        while (second != nextHead) {
            // origin
            // -1 -> 1 -> 2 -> 3 -> 4 -> 5
            //  |    |    |              |
            //  p    f    s            next
            //
            // after reverse
            // -1 -> 2 -> 1 -> 3 -> 4 -> 5
            //  |         |    |        |
            //  p         f    s       next
            //
            // after reverse at second time
            // -1 -> 3 -> 2 -> 1 -> 4 -> 5
            //  |                   |    | 
            //  p                   f    s = next

            first->next = second->next;
            second->next = pre->next;
            pre->next = second;
            second = first->next;
        }

        return first;
    }
};
// @lc code=end

