/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Solution 1: Resursion 1
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if (!head) {
//             return NULL;
//         }

//         if (!head->next) {
//             return new TreeNode(head->val);
//         }

//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = slow;

//         // find the middle point as root node
//         while (fast->next && fast->next->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // create the root node
//         TreeNode* root = new TreeNode(slow->val);

//         // check sub left list of the head 
//         if (slow != head) {
//             prev->next = NULL;
//             root->left = sortedListToBST(head);
//         }

//         // break the right list of the slow node 
//         // that is the right sub tree
//         ListNode* rightHead = slow->next;
//         root->right = sortedListToBST(rightHead);
        
//         return root;
//     }
// };

// Solution 2: Resursion 2
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }

        return recursion(head, NULL);
    }

    TreeNode* recursion(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = recursion(head, slow);
        root->right = recursion(slow->next, tail);
        return root;
    }
};
// @lc code=end

