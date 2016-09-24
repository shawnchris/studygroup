/**
88. Merge Sorted Array

Total Accepted: 121090
Total Submissions: 392009
Difficulty: Easy

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space 
(size that is greater or equal to m + n) 
to hold additional elements from nums2. 
The number of elements initialized in 
nums1 and nums2 are m and n respectively
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int idx_m = m - 1;
        int idx_n = n - 1;
        while (idx_n >= 0) {
            if (idx_m >= 0 && nums1[idx_m] > nums2[idx_n]) {
                nums1[tail] = nums1[idx_m];
                idx_m--;
            } else {
                nums1[tail] = nums2[idx_n];
                idx_n--;
            }
            tail--;
        }
    }
};