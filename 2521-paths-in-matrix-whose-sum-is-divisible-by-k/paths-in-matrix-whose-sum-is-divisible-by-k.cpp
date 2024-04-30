class Solution {
    
    int mod  = 1e9  + 7;
    int solve(vector<vector<int>>& grid, int k, int i, int j, int n, int m, int sum,vector<vector<vector<int>>> & dp){
        if(i == n || j == m)
            return 0;
        
    
        if(i == n-1 && j == m-1){
           
            return ((sum + grid[i][j]) % k  == 0);
        }
        if(dp[i][j][sum] != -1)
            return dp[i][j][sum];
        
        return dp[i][j][sum]  = (solve(grid, k, i+1, j, n, m,(sum + grid[i][j]) % k ,dp) + solve(grid, k, i, j+1, n, m, (sum + grid[i][j]) % k,dp)) % mod ;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(grid, k, 0, 0, n, m, 0, dp);

        
    }
};