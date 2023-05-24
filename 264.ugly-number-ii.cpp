/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        // the heads of each product list
        int p2 = 0, p3 = 0, p5 = 0;

        // product values
        int product2 = 1, product3 = 1, product5 = 1;
        
        // the total n results in an array
        vector<int> ugly(n, 0);

        // the current index
        int p = 0;
        
        while (p < ugly.size()) {
            // 1, 1*2, 1*3, 2*2, 1*5, 4*2, 3*3, 2*5
            int val = min(product2, min(product3, product5));
            ugly[p] = val;
            //printf("p: %d, val: %d\n", p, val);
            p++;

            // 1*2, 2*2, 3*2, 4*2, 5*2
            if (val == product2) {
                product2 = ugly[p2] * 2;
                p2++;
            }

            // 1*3, 2*3, 3*3 4*3, 5*3
            if (val == product3) {
                product3 = ugly[p3] * 3;
                p3++;
            }

            // 1*5, 2*5, 3*5, 4*5, 5*5
            if (val == product5) {
                product5 = ugly[p5] * 5;
                p5++;
            }
            //print(ugly);
        }

        return ugly[p - 1];
    }

    void print(vector<int>& ugly) {
        printf("[");
        for (auto num : ugly) {
            printf("%d, ", num);
        }
        printf("]\n");
    }
};
// @lc code=end

