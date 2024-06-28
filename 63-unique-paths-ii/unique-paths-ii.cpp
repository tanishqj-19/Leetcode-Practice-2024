class Solution {

    int n,m;
    int solve(int i, int j,vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= n || j >= m || grid[i][j])
            return 0;
        if(i == n-1 && j == m-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = solve(i , j + 1, grid, dp);
        int down = solve(i + 1, j , grid, dp);

        return dp[i][j] = left + down;
    }
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, grid, dp);


    }
};