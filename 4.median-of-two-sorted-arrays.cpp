/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
// Solution reference 1: https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
// Solution reference 2: https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLen = nums1.size() + nums2.size();

        if (totalLen % 2 == 0) { // even
            // 1, 2, 3, 4,| 5, 6, 7, 8 ==> (m + n) / 2 = (m + n + 1) / 2
            int midLeft = totalLen / 2 - 1;
            int midRight = totalLen / 2;
            double median = (getKth(nums1, nums2, midLeft + 1) + getKth(nums1, nums2, midRight + 1)) / 2.0;
            return median;
        } else {
            // we assume the median num is divided in the left side 
            // which is the biggest num 
            // 1, 2, 3, 4,| 5, 6, 7 (m + n + 1 = 8, 8 / 2 = 4)
            //          |
            //        mdeian
            int mid = totalLen / 2;
            double median = getKth(nums1, nums2, mid + 1);    
            return median;        
        }
    }

    double getKth(vector<int>& nums1, vector<int>& nums2, int k) {
        // remember, our purpose is to find out the kth and it's
        // start from 1 to m+n size, it differ from index

        int len1 = nums1.size();
        int len2 = nums2.size();

        int idx1 = 0;
        int idx2 = 0;

        while (true) {
            // edge cases
            if (len1 == idx1) {
                return nums2[idx2 + k - 1];
            }

            if (len2 == idx2) {
                return nums1[idx1 + k - 1];
            }

            // find result for median
            // remember, our purpose is to find out the kth small
            // num in the two sorted arrays, so when k = 1, which means
            // the k is in A[] or B[] element and it's in k = 0
            if (k == 1) {
                return  min(nums1[idx1], nums2[idx2]);
            }

            // find kth
            int half = k / 2;

            // if k / 2 is bigger than the size of one of sorted array,
            // we can put the final position as newIdx1 and newIdx2
            // to prevent idx1 + half is over the size two arrays are
            int newIdx1 = min(idx1 + half, len1) - 1;
            int newIdx2 = min(idx2 + half, len2) - 1;

            if (nums1[newIdx1] > nums2[newIdx2]) {
                // we cannot update k = k / 2 because we need to consider
                // the case when k is bigger than the size of one of sorted arrays
                // just minus the origin index 
                k -= (newIdx2 - idx2 + 1); 
                idx2 = newIdx2 + 1; // start at next index
            } else { // nums1[newIdx1] <= nums2[newIdx2]
                k -= (newIdx1 - idx1 + 1);
                idx1 = newIdx1 + 1; // start at next index
            }
        }
    }
};
// @lc code=end

