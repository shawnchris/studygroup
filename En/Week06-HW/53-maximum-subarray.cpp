/**
 * https://leetcode.com/problems/maximum-subarray/
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4], 
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

// slow version, no dp
#include <math.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// dp version
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < len; i++) {
               sum = max(nums[i], nums[i] + sum);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};