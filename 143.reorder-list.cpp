/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tail = reverse(slow->next);
        slow->next = NULL;


        ListNode* cur = dummy->next;
        while (cur && tail) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = tail->next;

            cur->next = tail;
            tail->next = tmp1;

            cur = tmp1;
            tail = tmp2;
        }

        head = dummy->next;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL; 
        
        return newHead;
    }
};
// @lc code=end

