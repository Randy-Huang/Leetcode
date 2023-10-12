/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
// DP
// class Solution {
// public:
//     int numDecodings(string s) {
//         // Define:
//         // d[i] represents the number of decoding ways 
//         // for substring ending at s[i]
//         int n = s.size();
//         if (n == 0 || s[0] == '0') {
//             return 0;
//         }
    
//         vector<int> dp((n + 1), 0);
//         dp[0] = 1;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++) {
//             // s[i - 1]: current pos of s
//             // s[i - 2]: last pos of s
            
//             // Check if the current digit is '0'. 
//             // If so, it cannot be decoded separately 
//             // and can only form 10 or 20 with the previous digit.
//             if (s[i-1] == '0') {
//                 if (s[i-2] == '1' || s[i-2] == '2') {
//                     // means 10 or 20
//                     // s = "220"
//                     // only (2, 20) 
//                     // we cannot decode s to (2, 2) that is valid
//                     // when s = "22" we have two decode ways
//                     // (2, 2) and (22) and dp is
//                     // dp[2] = dp[0] + dp[1] = 1 + 1
//                     // but in 220 case, we only decode with "20"
//                     // but (2, 0) which means s[1] need to be combine
//                     // with s[2] to decode together, therefore
//                     // dp[3] is based on the dp[1]
//                     dp[i] =  dp[i-2];
//                 } else {
//                     // If the current digit is '0' and cannot be 
//                     // form 10 or 20 with the previous digit, 
//                     // the whole string cannot be decoded.
//                     return 0;
//                 }
//             } else {
//                 if (10 <= stoi(s.substr(i-2, 2)) && stoi(s.substr(i-2, 2)) <= 26) {
//                     // Check if the current digit can form 
//                     // a valid number (10 to 26) with the previous digit.
//                     dp[i] = dp[i-1] + dp[i-2];
//                 } else {
//                     // If the current digit cannot form 
//                     // a valid number with the previous digit, 
//                     // the decoding ways are the same as the previous one.

//                     // s = "2268" 
//                     // => (2, 2, 6, 8), (22, 6, 8), (2, 26, 8)
//                     dp[i] = dp[i-1];
//                 }
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp(3, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    dp[2] = dp[0];
                } else {
                    return 0;
                }
            } else {
                if (10 <= stoi(s.substr(i-1, 2)) && stoi(s.substr(i-1, 2)) <= 26) {
                    dp[2] = dp[0] + dp[1];
                } else {
                    dp[2] = dp[1];
                }
            }

            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return n >= 2 ? dp[2] : dp[0];
    }
};
// @lc code=end

