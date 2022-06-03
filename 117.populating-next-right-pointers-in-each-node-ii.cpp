/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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

        // Find the next node of the current node
        Node* next = root->next;
        while (next) {
            if (next->left) {
                next = next->left;
                break;
            }

            if (next->right) {
                next = next->right;
                break;
            }

            next = next->next;
        }

        if (root->right) {
            root->right->next = next;
        }

        if (root->left) {
            root->left->next = root->right ? root->right : next;
        }

        // Notice here!
        // In case of the null node from the right side node
        // so we recursive the node from the right side branch
        // to handle the coneection 
        // which means the connection from right side to the left side
        recursive(root->right);
        recursive(root->left);
    }

    void iterative(Node* root) {
        if (!root) {
            return;
        }

        Node* level = root;

        // iterate the tree's level
        while (level) {
            Node* current = level;
            Node* NextLevelhead = NULL;

            // iterate the nodes in the same level
            while (current) {

                // find the next node's first child 
                // that the current's child nodes connect to
                Node* nextChild = current->next;
                while (nextChild) {
                    if (nextChild->left) {
                        nextChild = nextChild->left;
                        break;
                    }

                    if (nextChild->right) {
                        nextChild = nextChild->right;
                        break;
                    }

                    nextChild = nextChild->next;
                }

                // We only can find the level head to iterate
                // the first node in this level
                if (!NextLevelhead) {
                    NextLevelhead = current->left ? current->left : current->right;
                }

                // do the connection from the right not the left
                if (current->right) {
                    current->right->next = nextChild;
                }

                if (current->left) {
                    current->left->next = current->right ? current->right : nextChild;
                }

                current = current->next;
            }

            level = NextLevelhead;
        }
    }
};
// @lc code=end

