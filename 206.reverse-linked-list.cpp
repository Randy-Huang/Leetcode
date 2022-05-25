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
        return recursive(head);
    }

    ListNode* iterative(ListNode* head) {
        ListNode* newHead = NULL;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
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

