/**
 * https://leetcode.com/problems/unique-paths/
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 */

// recursion version
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > v(m+1, vector<int> (n+1, 1));
        return helper(m, n, v);
    }
    
    int helper(int m, int n, vector<vector<int>> &v) {
        if (m == 1 || n == 1 || v[m][n] != 1) {
            return v[m][n];
        }
        v[m][n] = helper(m-1, n, v) + helper(m, n-1, v);
        return v[m][n];
    }
};