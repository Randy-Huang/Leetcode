/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
// Solution 1: DP
class Solution 
{
public:
    int racecar(int target) 
    {
        // What things we need to figure out?
        //
        // 1. position changed by speed in "A" (it's same as "R")
        // we've known the relation between position and speed by the description:
        //
        // position += speed
        // speed *= 2
        //
        // so if we keep straight forward to target,
        // then the position changed by speed:
        // 0 -> 1 -> 3 -> 7 -> 15 -> 31
        //
        // which means (2^speed change count), then we have:
        // (2^0)-1 -> (2^1)-1 -> (2^2)-1 -> (2^3)-1 -> (2^4)-1 -> (2^5)-1
        // (1)-1   -> (2)-1   -> (4)-1   -> (8)-1   -> (16)-1  -> (32)-1 
        //
        // 2. How many ways do we have to choose to arrive the target?
        // case 1: keep forwards to the target withough reverse
        // case 2: keep forwards to and over head of the target, then we need to reverse once
        // case 3: keep forwards to a certain distance but not arrive to the target, we reverse
        //         the direction to move backwards and then reverse again to forwards to the target
        //         in this case, we need to reverse twice.
        // case 4: keep forwards to and over head of the target, then we need to reverse 
        //         the direction to move backwards but still cannot reach to the target,
        //         which means we're over the target again, so we have to reverse again
        //         to forwards to the target. in this case, we need to reverse twice.
        // 
        // To conclude the 4 cases, we can know the fact that:
        // case 1: 0 reverse
        // case 2: 1 reverse
        // case 3: 2 reverse (or even more)
        // case 4: 2 reverse (or even more)
        // so we can combine 3 and 4 in the same case
        // we also can combine 1,2 in the same case with 2 different conditions.
        //
        // then we can have the following equation:
        // A - (RA)_1 + (RA)_2 - (RA)_3 + ...
        // 
        // 3. DP definition
        // We allocate one demition vector DP that size is target + 1
        // Let i is the postion and result is the needed command at least
        //
        // Here we have: dp[i] = result 
        //
        // and the base case is dp[0] = 0 and dp[1] = 1
        vector<int> dp(target + 1);
        dp[0] = 0; // N/A
        dp[1] = 1; // A

        for (int pos = 2; pos <= target; pos++ )
        {
            // base case to compare which stpes is smaller
            dp[pos] = INT_MAX;

            int pPos = 1;
            int pCmd = 1;

            // the following two for loops can be expressed
            // (RA)_1 - (RA)_2
            for (; pos > pPos; (pPos = (1 << (++pCmd)) - 1)) 
            {
                int nPos = 0;
                int nCmd = 0;
                for (; pPos > nPos; (nPos = (1 << (++nCmd)) - 1)) 
                {
                    // before reaching target, we have one return 
                    // to backwards and then reverse again to forwards
                    const int twiceR = 2;
                    dp[pos] = min(dp[pos], (pCmd + nCmd + twiceR + dp[pos - (pPos - nPos)]));
                }
            }

            // when car past target then we need to return back to the target
            const int onceR = 1;

            // (A)_1 - (RA)_2
            dp[pos] = min(dp[pos], (pos == pPos ? pCmd : (onceR + pCmd + dp[pPos - pos])));
        }

        return dp[target];
    }
};
// @lc code=end

