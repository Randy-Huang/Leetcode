/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; fast; i++) {
            fast = fast->next;
            if (i > n) {
                slow = slow->next;
            }
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};
// @lc code=end

