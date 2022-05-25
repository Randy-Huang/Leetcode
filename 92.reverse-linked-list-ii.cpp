/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
// Reference by Leetcode official: https://leetcode.com/problems/reverse-linked-list-ii/solution/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return iterate(head, left, right);
    }

    // Approach 1: Recursion
    ListNode* leftNode;
    bool stopChange;
    ListNode* recursiveReverse(ListNode* head, int left, int right) {
        leftNode = head;
        stopChange = false;
        recursive(head, left, right);
        return head;
    }

    void recursive(ListNode* rightNode, int left, int right) {
        if (right == 1) {
            return;
        }

        // Keep moving the right pointer one step forward until (right == 1)
        rightNode = rightNode->next;
        right--;

        // Keep moving left pointer to the right until we reach the proper node
        // from where the reversal is to start.
        if (left > 1) {
            leftNode = leftNode->next;
            left--;
        }

        // Recurse with m and n reduced.
        recursive(rightNode, left, right);

        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if (leftNode == rightNode || (rightNode->next = leftNode)) {
            stopChange = true;
        }

        // Until the boolean stop is false, swap data between the two pointers
        if (!stopChange) {
            int tmp = rightNode->val;
            rightNode->val = leftNode->val;
            leftNode->val = tmp;

            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            leftNode = leftNode->next;
        }
    }

    // Approach 2: Iterative Link Reversal
    ListNode* iterate(ListNode* head, int left, int right) {
        if (!head) {
            return head;
        }

        // Move the two pointers until they reach the proper 
        // starting point in the list.
        ListNode* newHead = NULL;
        ListNode* cur = head;
        while (left > 1) {
            newHead = cur;
            cur = cur->next;
            left--;
            right--;
        }

        // The two pointers that will fix the final connections.
        // one is the pre node which point at the right node of
        // the new head of sublist
        // another point at the first node of the sublist.
        // at the end tail will become the tail of the sublist
        ListNode* pre = newHead;
        ListNode* tail = cur;

        // Let cur node to iterate until it reaches the right node of sublist
        // Iteratively reverse the nodes until n becomes 0.
        while (right > 0) {
            ListNode* tmp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = tmp;
            right--;
        }

        if (pre) { 
            pre->next = newHead;
        } else {
            // if left is 1 which means pre never move 
            // just assined newHead to head
            head = newHead;
        }
        tail->next = cur;

        return head;
    }
};
// @lc code=end

