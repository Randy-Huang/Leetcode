/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
const static int ALPHABET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children;
    string word;
    bool isEndOfWord;

    TrieNode() {
        children = vector<TrieNode*>(ALPHABET_SIZE, NULL);
        isEndOfWord = false;
        word = "";
    };
};

// Use class
class Trie {
private:
    TrieNode* createNode() {
        return new TrieNode();
    }

    TrieNode* root;
public:
    Trie() {
        root = createNode();
    }

    void addWord(string word) {
        TrieNode* current = root;
        for (auto& c : word) {
            int i = c - 'a';
            if (!current->children[i]) {
                current->children[i] = createNode();
            }
            current = current->children[i];
        }
        current->isEndOfWord = true;
        current->word = word;
    }

    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isAllFound = false;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        int n = board[0].size();
        if (m < 0 || n < 0) {
            return res;
        }

        Trie *trie = new Trie();
        for (auto& word : words) {
            trie->addWord(word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isAllFound) {
                    return res;
                }
                search(trie->getRoot(), board, i, j, res, words);
            }
        }

        return res;
    }

    void search(TrieNode* current, vector<vector<char>>& board, int i, int j, vector<string>& res, vector<string>& words)  {
        if (res.size() == words.size()) {
            isAllFound = true;
            return;
        }
        if (current && current->isEndOfWord) {
            res.push_back(current->word);
            current->isEndOfWord = false;
        }

        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' || !current->children[board[i][j] - 'a']) {
            return;
        }

        current = current->children[board[i][j] - 'a'];
        char temp = board[i][j];
        board[i][j] = '#';
        search(current, board, (i + dirs[0][0]), (j + dirs[0][1]), res, words);
        search(current, board, (i + dirs[1][0]), (j + dirs[1][1]), res, words);
        search(current, board, (i + dirs[2][0]), (j + dirs[2][1]), res, words);
        search(current, board, (i + dirs[3][0]), (j + dirs[3][1]), res, words);
        board[i][j] = temp;
    }
};
// @lc code=end

