/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1, l2, 0);
    }

    ListNode* recursive(ListNode* l1, ListNode* l2, int carry) {
        // base case
        if (!l1 && !l2) {
            if (carry) {
                return new ListNode(carry);
            } 

            return NULL;
        }

        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode* node = new ListNode(sum % 10);
        node->next = recursive(l1, l2, (sum / 10));

        return node;
    }

    ListNode* iterative(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        int carry = 0;
        while (l1 || l2 || (carry > 0)) {
            int sum = carry;
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            current->next = node;
            current = current->next;
        }
        
        return dummy->next;
    }
};
// @lc code=end

