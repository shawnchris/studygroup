/**
 * https://leetcode.com/problems/unique-paths-ii/
 *
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 */

// recursive version
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        return helper(obstacleGrid, m-1, n-1, v);
    }
    
    int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& v) {
        if (m == 0 && n == 0) {
            v[m][n] = 1;
        } else if (v[m][n] == -1){
            v[m][n] = 0;
            if(m != 0 && grid[m-1][n] != 1) {
                v[m][n] += helper(grid, m-1, n, v);
            }
            if(n != 0 && grid[m][n-1] != 1) {
                v[m][n] += helper(grid, m, n-1, v);
            }
        }
        return v[m][n];
    }
};