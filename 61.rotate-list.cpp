/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
// Solution 1: iteration
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (!head) {
//             return NULL;
//         }

//         // 1. calculate list size
//         int size = 1;
//         ListNode* current = head;
//         while (current->next) {
//             current = current->next;
//             size++;
//         }

//         // 2. let tail node to connect to the head
//         // if we don't do this first, we're going to 
//         // face many edge cases need to handle especially
//         // list has only one or two.
//         current->next = head;

//         // 3. move to the new tail node that move is 0
//         int move = size - (k % size);
//         while (move > 0) {
//             move--;
//             current = current->next;
//         }

//         // 4. Assign new head with current's next node
//         ListNode* newHead = current->next;
//         current->next = NULL;

//         return newHead;
//     }
// };
// Solution 2: Resursion
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }

        int size = getSize(head);
        int move = k % size;
        if (move == 0) {
            return head;
        }

        rotate(head, head, NULL, move);
        
        return head;
    }

    void rotate(ListNode*& head, ListNode* current, ListNode* prev, int& move) {
        if (!current) {
            return;
        }

        rotate(head, current->next, current, move);

        move--;
        if (move < 0) {
            return;
        }
        prev->next = NULL;
        current->next = head;
        head = current;
    }

    int getSize(ListNode* head) {
        if (!head) {
            return 0;
        }

        return 1 + getSize(head->next);
    }
};
// @lc code=end

