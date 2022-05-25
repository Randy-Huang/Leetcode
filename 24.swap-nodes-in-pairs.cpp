/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        return iterate(head);
    }

    ListNode* iterate(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;

        while (pre->next && pre->next->next) {
            ListNode *second = pre->next->next;
            pre->next->next = second->next;
            second->next = pre->next;
            pre->next = second;
            pre = second->next;
        }

        return dummy->next;
    }

    ListNode* recursive(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* second = head->next;
        head->next = recursive(head->next->next); 
        second->next = head;
        return second;
    }
};
// @lc code=end

