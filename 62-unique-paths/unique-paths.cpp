class Solution {
    int solve(int i, int j, int n, int m,vector<vector<int>> &dp){
        if(i >= n || i < 0 || j < 0 || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == n-1 && j == m-1)
            return 1;

        int down = solve(i + 1, j, n, m, dp);
        int left = solve(i, j + 1, n, m, dp);

        return dp[i][j] = left + down;
        
    }
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};