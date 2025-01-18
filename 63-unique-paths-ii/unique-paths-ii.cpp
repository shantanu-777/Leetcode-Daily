class Solution {
public:
    int countpath(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // Base cases
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0; // Out of bounds or obstacle
        if (i == 0 && j == 0) return obstacleGrid[i][j] == 0 ? 1 : 0; // Starting point
        
        // Use memoized result if available
        if (dp[i][j] != -1) return dp[i][j];
        
        // Calculate paths from top and left cells
        int count = 0;
        if (i > 0) count += countpath(i - 1, j, obstacleGrid, dp); // Move up
        if (j > 0) count += countpath(i, j - 1, obstacleGrid, dp); // Move left
        
        return dp[i][j] = count; // Store result
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Initialize dp array with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Start recursion from the bottom-right corner
        return countpath(m - 1, n - 1, obstacleGrid, dp);
    }
};