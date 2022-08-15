/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        return iterate(head);
    }

    Node* iterate(Node* head) {
        if (!head) {
            return NULL;
        }

        Node* current = head;
        while (current) {
            Node* clone = new Node(current->val, NULL, NULL);
            clone->next = current->next;
            current->next = clone;
            current = current->next->next;
        }

        current = head;
        while (current) {
            if (current->random) {
                // here we need to be careful, we must set the next of new node
                // for the reference to new random one,
                // not a original one
                current->next->random = current->random->next;
            }
            
            current = current->next->next;
        }

        current = head;
        Node* cloneHead = current->next;
        while (current) {
            Node* clone = current->next;
            current->next = clone->next;

            if (clone->next) {
                clone->next = clone->next->next;
            }
            current = current->next;
        }

        return cloneHead;
    }

    Node* dfs(Node* head) {
        unordered_map<Node*, Node*> map;
        dfsTraversal(head, map);
        return map[head];
    }

    void dfsTraversal(Node* node, unordered_map<Node*, Node*>& map) {
        if (!node) {
            return;
        }

        if (map.count(node)) {
            return;
        }

        Node* clone = new Node(node->val);
        map[node] = clone;

        dfsTraversal(node->next, map);
        dfsTraversal(node->random, map);

        clone->next = map[node->next];
        clone->random = map[node->random];
    }
};
// @lc code=end

