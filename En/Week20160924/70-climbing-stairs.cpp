/**
70. Climbing Stairs  

Total Accepted: 131137
Total Submissions: 345718
Difficulty: Easy

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

class Solution {
public:
    int climbStairs(int n) {
        // This problem is like fibonacci sequnence.
        // Solution is DP
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int f = 1;
        int g = 2;
        while (2 < n--) {
            g = g + f;
            f = g - f;
        }
        return g;
    }
};