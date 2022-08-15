// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem452.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    static bool sortAscendingOrder(vector<int>& a, vector<int>& b) {
        return b[1] > a[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        if (size == 1) {
            return 1;
        }

        sort(points.begin(), points.end(), sortAscendingOrder);

        int count = 0;
        int current = points[0];

        for (auto point : points) {
            if (current[1] < point(0)) {
                count++;
                current = point;
            }
        }

        return count;
    }
};
// @lc code=end

