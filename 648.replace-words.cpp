/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
// Solution 1: Trie
// const static int ALPHABET_SIZE = 26;

// struct TrieNode {
//     vector<TrieNode*> children;
//     bool isEndOfWord;

//     TrieNode() {
//         children = vector<TrieNode*>(ALPHABET_SIZE, NULL);
//         isEndOfWord = false;
//     }
// };

// class Trie {
// private:
//     TrieNode* root;

//     TrieNode* createNode() {
//         return new TrieNode();
//     }

// public:
//     Trie() {
//         root = createNode();
//     }

//     void addWord(string word) {
//         TrieNode* current = root;
//         for (auto& c : word) {
//             int i = c - 'a';
//             if (!current->children[i]) {
//                 current->children[i] = createNode();
//             }

//             current = current->children[i];
//         }
//         current->isEndOfWord = true;
//     }

//     string findAndReplace(string word) {
//         TrieNode* current = root;
//         string lookUp = "";
//         for (auto& c : word) {
//             int i = c - 'a';
//             if (current->isEndOfWord) {
//                 break;
//             }

//             if (!current->children[i]) {
//                 lookUp = "";
//                 break;
//             }

//             lookUp += c;
//             current = current->children[i];
//         }

//         return lookUp;
//     }
// };

// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         string res = "";

//         Trie* trie = new Trie();
//         for (auto& sentence : dictionary) {
//             trie->addWord(sentence);
//         }

//         string word = "";
//         for (int i = 0; i <= sentence.size(); i++) {
//             char c = sentence[i];
//             if (c == ' ' || c == '\0') {
//                 string temp = trie->findAndReplace(word);

//                 if (temp == "") {
//                     res = helper(res, word);
//                 } else {
//                     res = helper(res, temp);
//                 }

//                 word = "";
//                 continue;
//             }

//             word += c;
//         }

//         return res;
//     }

//     string helper(string res, string word) {
//         return res.size() == 0 ? word : (res + " " + word);
//     }
// };

// Solution 2: Hash table
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> rootset;
        for (auto& word : dictionary) {
            rootset.insert(word);
        }

        string res = "";
        string prefix = "";
        for (int i = 0; i <= sentence.size(); i++) {
            auto it = rootset.find(prefix);
            if (it != rootset.end()) {
                while (sentence[i] != ' ' && sentence[i] != '\0') {
                    i++;
                }
            }

            if (sentence[i] == ' ' || sentence[i] == '\0') {
                res += (res.size() > 0 ? " " : "");
                res += prefix;
                prefix = "";
                continue;
            }

            prefix += sentence[i];
        }

        return res;
    }
};
// @lc code=end

