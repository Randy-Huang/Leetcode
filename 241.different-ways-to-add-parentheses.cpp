/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return divideAndConquer(memo, expression);
    }

    int to_int(string num) {
        int res = 0;
        for (auto c : num) {
            res = res * 10 + (c - '0');
        }
        return res;
    }

    vector<int> divideAndConquer(unordered_map<string, vector<int>>& memo, string expression) {
        vector<int> res;
 
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = divideAndConquer(memo, expression.substr(0, i));
                vector<int> right = divideAndConquer(memo, expression.substr(i + 1));
                /* 
                 * the set of operations between left and right 
                 *
                 *  (1) + (2 * 3 - 4 * 5)
                 *
                 *  (1 + 2) * (3 - 4 * 5)
                 *  
                 *  (1 + 2 * 3) - (4 * 5)
                 * 
                 *  (1 + 2 * 3 - 4) * (5)
                 */
                
                for (int a : left) {
                    for (int b : right) {
                        // printf("i: %d, left size: %d, value: %d, right size: %d, value: %d\n", i, left.size(), a, right.size(), b);
                        if (c == '+') {
                            res.push_back(a + b);
                        } else if (c == '-') {
                            res.push_back(a - b);
                        } else if (c == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }

        // base case
        // reduce the redundent computing
        // for example:
        // we have an expression of 1 + 1 + 1 + 1 + 1
        //
        // there are two result of sub string shoud be the same:
        // (1 + 1) + (1 + 1 + 1)
        //         and
        // (1 + 1 + 1) + (1 + 1)
        // so we can use hashtable to reduce the computing
        if (res.empty()) {
            res.push_back(to_int(expression));
        }

        memo[expression] = res;
        return res;
    }
};
// @lc code=end

