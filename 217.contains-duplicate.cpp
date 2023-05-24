/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return hashtable(nums);
    }

    bool hashtable(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) {
                return true;
            }

            map[nums[i]]++;
        }

        return false;
    }

    // solution 2: sort using merge sort
    bool sort(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }

        return false;
    }

    void dump(vector<int>& nums) {
        printf("[");
        for (int i = 0; i < nums.size(); i++) {
            printf("%d, ", nums[i]);
        }
        printf("]\n");
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> temp(end - start + 1);
        int i = start; // to mid
        int j = mid + 1; // to end
        int k = 0;

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i + start] = temp[i];
        }
    }
};
// @lc code=end

