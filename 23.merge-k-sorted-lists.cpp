/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Solution 1:
        // return helper(lists, 0, lists.size()-1);

        // Solution 2:
        return prioritQueue(lists);
    }

    // Solution 2: priority queue with min heap
    ListNode* prioritQueue(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto head : lists) {
            if (head) {
                printf("val: %d\n", head->val);
                pq.push(head);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while (!pq.empty()) {
            ListNode* tmp = pq.top(); pq.pop();
            current->next = tmp;
            current = current->next;
            if (tmp->next) {
                pq.push(tmp->next);
            }
        }

        return dummy->next;
    }


    // Solution 1: merge sort
    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        }

        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        if (!L1) {
            return L2;
        }

        if (!L2) {
            return L1;
        }
        //printf("L1: %d, L2: %d\n", L1->val, L2->val);

        if (L1->val < L2->val) {
            L1->next = mergeTwoLists(L1->next, L2);
            //printNode(L1);
            return L1;
        } else {
            L2->next = mergeTwoLists(L1, L2->next);
            //printNode(L2);
            return L2;
        }
    }

    void printNode(ListNode* root) {
        bool isEmpty = root == NULL;
        while (root) {
            printf("%d", root->val);
            if (root->next) {
                printf("->");
            }
            root = root->next;
        }

        if (!isEmpty) {
            printf("\n");
        }
    }

};
// @lc code=end

