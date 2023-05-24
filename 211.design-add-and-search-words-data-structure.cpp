/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode() : isEndOfWord(false) {}

        ~TrieNode() {
            for (auto child : children) {
                if (child.second) {
                    delete (child.second);
                }
            }
        }
    };

    struct TrieNode* createNode(void) {
        struct TrieNode* node = new TrieNode;
        return node;
    };

    // Judge the input patten 
    // be careful, for the recursion, if we have the input is the same
    // just use call by reference, for example, the parameter word
    // we use call by reference to recursive,
    // if we don't use it, system will increase run time and 
    // lead to over time limit
    bool searchWordByPattern(TrieNode* current, string& word, int index) {
        // case 1: 
        // if index is the same as the word size
        // just check the flag "isEndOfWord"
        // to match the word partten
        if (word.size() == index) {
            return current->isEndOfWord;
        }

        char c = word[index];
        if (c == '.') {
            // case 2:
            // if we iterate the character is '.'
            // we don't need to compare them but
            // we need to iterate all the children of the current node
            for (auto child : current->children) {
            //for (auto child = current->children.begin(); child != current->children.end(); child++) {
                if (searchWordByPattern(child.second, word, index + 1)) {
                    return true;
                }
            }
        } else {
            // case 3: recursively find the match character if it exist 
            if (current->children.find(c) != current->children.end()) {
                return searchWordByPattern(current->children[c], word, index + 1);
            }
        }

        return false;
    }

    struct TrieNode* root;

public:
    WordDictionary() {
        root = createNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for (auto c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = createNode();
            }

            current = current->children[c];
        }

        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        // start searching from 0 using DFS
        return searchWordByPattern(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

