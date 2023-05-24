/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string track;

        // all n of the parentheses, we must have n left and n right
        // which means we will have 2n parentheses
        backtracking(n, n, track, res);

        return res;
    }

    void backtracking(int left, int right, string& track, vector<string>& res) {
        // an valid parentheses is the fact that the left parenthesis always must 
        // greater than or equal to the right parenthesis
        if (left > right) {
            return;
        }

        // prevent the negative parenthesis
        if (left < 0 || right < 0) {
            return;
        }

        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        // for the left
        track.push_back('(');
        backtracking(left - 1, right, track, res);
        track.pop_back();

        // for the right
        track.push_back(')');
        backtracking(left, right - 1, track, res);
        track.pop_back();
    }
};
// @lc code=end

