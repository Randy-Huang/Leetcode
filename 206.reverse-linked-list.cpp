/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
// Reference: https://www.cnblogs.com/grandyang/p/4478820.html
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return iterative(head);
    }

    ListNode* iterative(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* current = head;

        while (current) {
            ListNode* tmp = current->next;
            current->next = pre;
            pre = current;
            current = tmp;
        }

        return pre;
    }

    ListNode* recursive(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
    
        return newHead;
    }
};
// @lc code=end

