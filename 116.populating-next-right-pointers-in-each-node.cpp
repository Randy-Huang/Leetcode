/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        iterative(root);
        return root;
    }

    void recursive(Node* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            root->left->next = root->right;
        }

        if (root->right) {
            root->right->next = root->next ? root->next->left : NULL;
        }

        recursive(root->left);
        recursive(root->right);
    }

    void iterative(Node* root) {
        if (!root) {
            return;
        }

        // Use level pointer to locate the parent nodes
        // and use another node 'current' to iterate the nodes
        // of the current level
        Node* level = root;

        while (level) {
            Node* current = level;
            while (current && current->left) {
                current->left->next = current->right;
                if (current->next) {
                    current->right->next = current->next->left;
                }
                current = current->next;
            }

            level = level->left;
        }
    }
};


// @lc code=end

