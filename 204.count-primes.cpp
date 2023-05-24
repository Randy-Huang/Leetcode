/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4462810.html
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;

        vector<bool> primes(n, true);

        // 1. iterate primes table to count the numbers
        // 2. when we iterate n, use the current number 
        //    to miltiple inner for loop from 2 to find out what numers 
        //    can satisfy the condition i * j < n which means
        //    a prime number
        for (int i = 2; i < n; i++) {
            if (!primes[i]) {
                continue;
            } 

            count++;

            for (int j = 2; (i * j) < n; j++) {
                primes[i * j] = false; 
            }
        }

        return count;
    }
};
// @lc code=end

