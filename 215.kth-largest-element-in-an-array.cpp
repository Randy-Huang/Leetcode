/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Solution 1: basic partition with Lomuto Partition Scheme
        // //print(nums);
        // int n = nums.size();
        // // quick select is used to find kth smallest element in an array
        // // for kth largest element, we can use "array size nums.size() - k" 
        // // converting the question to finding kth largest element
        // return quickSelect(nums, n - k, 0, n - 1);

        // Solution 2: advanced partition selection with Hoare partition scheme
        int n = nums.size();
        int target = n - k;
        int l = 0;
        int r = n - 1;
        return quickSelectAdvanced(nums, target, l, r);
    }

    void print(vector<int>& nums) {
        printf("[");
        for (int i = 0; i < nums.size(); i++) {
            printf("%d,", nums[i]);
        }
        printf("]\n");
    }

    int quickSelectAdvanced(vector<int>& nums, int target, int l, int r) {
        int pivotIndex = partitionAdvanced(nums, l, r);
        if (pivotIndex == target) {
            return nums[pivotIndex];
        }

        return pivotIndex > target ? 
            quickSelectAdvanced(nums, target, l, pivotIndex - 1) : 
            quickSelectAdvanced(nums, target, pivotIndex + 1, r);
    }

    int partitionAdvanced(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int lo = l;
        int hi = r - 1;
        //printf("origin: l: %d, r: %d\n", l,r);
        //print(nums);
        while (lo <= hi) {
            while (lo <= hi && nums[lo] <= pivot) {
                //printf("lo: %d, nums[lo]: %d\n", lo, nums[lo]);
                lo++;
            }

            while (lo <= hi && nums[hi] >= pivot) {
                //printf("hi: %d, nums[hi]: %d\n", hi, nums[hi]);
                hi--;
            }
            //printf("lo: %d, hi: %d\n", lo, hi);
            if (lo < hi) {
                //printf("swap\n");
                //print(nums);
                swap(nums[lo], nums[hi]);
            }
        }   

        swap(nums[lo], nums[r]);
        return lo;
    }

    int quickSelect(vector<int>& nums, int k, int l, int r) {
        if (l <= r) {
            int pivot = partition(nums, l, r);
            //print(nums);
            //printf("pivot: %d\n", pivot);
            if (pivot == k) {
                return nums[k];
            }

            // it measn all elements in the left part of the index i 
            // are smaller than nums[i], we just keep searching 
            // for the right part
            if (pivot < k) {
                //printf("search right part\n");
                return quickSelect(nums, k, pivot + 1, r);
            }

            // if (pivot > k) 
            // it measn all elements in the right part of the index i 
            // are greater than nums[i], we just keep searching 
            // for the left part
            printf("search left part\n");
            return quickSelect(nums, k, l, pivot - 1);
        }

        return INT_MIN;
    }

    // base partition algorithm (Lomuto Partition Scheme)
    int partition(vector<int>& nums, int l, int r) {

        // Standard partition process of QuickSort().
        // It considers the last element as pivot
        // and moves all smaller element to left of
        // it and greater elements to right
        int pivot = nums[r];

        // starts from the left side to search
        int i = l;
        for (int j = l; j < r; j++) {
            // iterate array to seach the value that smaller or equals
            // to pivot and swpt nums[i] and nums[j] to put the value
            // to the left part
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        // i is at the beginning of the right part 
        // At the end, we swap nums[r] and nums[i]
        // and return the new pos r to the caller
        // now at the left part of nums[i] is smaller part
        // right part is the greater part
        swap(nums[i], nums[r]);
        return i;
    }
};
// @lc code=end

