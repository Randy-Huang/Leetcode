/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

// class Trie {
// private:
//     const static int ALPHABET_SIZE = 26;

//     struct TrieNode {
//         // struct TrieNode* children[ALPHABET_SIZE];
//         vector<TrieNode*> children;

//         // isEndOfWord is true if the node
// 		// represents the end of a word
//         bool isEndOfWord;

//         TrieNode() {
//             isEndOfWord = false;
//             children = vector<TrieNode*>(ALPHABET_SIZE, NULL);
//         }

//         ~TrieNode() {
//             for (auto child : children) {
//                 if (child) {
//                     delete child;
//                 }
//             }
//         }
//     };

//     // Returns new trie node (initialized to NULLs)
//     struct TrieNode* createNode(void) {
//         struct TrieNode* node = new TrieNode;
//         node->isEndOfWord = false;

//         return node;
//     };

//     struct TrieNode* root;

// public:
//     Trie() {
//         root = createNode();
//     }
    
//     // If not present, inserts key into trie
//     // If the key is prefix of trie node, just
//     // marks leaf node
//     void insert(string word) {
//         TrieNode* current = root;

//         for (auto c : word) {
//             int index = c - 'a';
//             if (current->children[index] == NULL) {
//                 current->children[index] = createNode();
//             } 
//             current = current->children[index];
//         }

//         // mark last node as leaf
//         current->isEndOfWord = true;
//     }
    
//     // Returns true if key presents in trie, else false
//     bool search(string word) {
//         TrieNode* current = root;

//         for (auto c : word) {
//             int index = c - 'a';
//             if (current->children[index] == NULL) {
//                 return false;
//             }
//             current = current->children[index];
//         }

//         return current->isEndOfWord;
//     }

//     // Returns true if root has no children, else false
//     bool isEmpty(TrieNode* root) {
//         for (int i = 0; i < ALPHABET_SIZE; i++) {
//             if (root->children[i]) {
//                 return false;
//             }
//         }

//         return true;
//     }

//     // Recursive function to delete a key from given Trie
//     // we delete the key in bottom-up manner using recursion
//     TrieNode* remove(TrieNode* root, string word, int depth = 0) {
//         // If tree is empty
//         if (!root) {
//             return NULL;
//         }

//         // 1. If last character of key is being processed
//         if (word.size() == depth) {

//             // This node is no more end of word after
//             // removal of given key
//             if (root->isEndOfWord) {
//                 root->isEndOfWord = false;
//             }

//             // If given is not prefix of any other word
//             if (isEmpty(root)) {
//                 root->~TrieNode();
//                 root = NULL;
//             }

//             return root;
//         }

//         // 2. If not last character, recur for the child
//         // obtained using ASCII value
//         int index = word[depth] - 'a';
//         root->children[index] = remove(root->children[index], word, depth + 1);

//         // If root does not have any child (its only child got
//         // deleted), and it is not end of another word.
//         if (isEmpty(root) && !root->isEndOfWord) {
//             root->~TrieNode();
//             root = NULL;
//         }

//         return root;
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* current = root;

//         for (auto c : prefix) {
//             int index = c - 'a';
//             if (current->children[index] == NULL) {
//                 return false;
//             }
//             current = current->children[index];
//         }

//         return true;
//     }
// };

// 2023.07.28
class Trie {    
private:
    const static int ALPHABET_SIZE = 26;

    struct TrieNode {
        vector<struct TrieNode*> children;
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            children = vector<TrieNode*>(ALPHABET_SIZE, nullptr);
        }
    };

    struct TrieNode* createNode() {
        struct TrieNode* node = new TrieNode();
        return node;
    };

    struct TrieNode* root;

public:
    Trie() {
        root = createNode();
    }

    void insert(string word) {
        struct TrieNode* current = root;

        for (auto& c : word) {
            int i = c - 'a';
            if (!current->children[i]) {
                current->children[i] = createNode();
            }
            current = current->children[i];
        }

        current->isEndOfWord = true;
    }

    bool search(string word) {
        struct TrieNode* current = root;
        for (auto& c : word) 
        {
            int i = c - 'a';
            if (!current->children[i]) {
                return false;
            }
            current = current->children[i];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        struct TrieNode* current = root;
        for (auto& c : prefix) {
            int i = c - 'a';
            if (!current->children[i]) {
                return false;
            }
            current = current->children[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

