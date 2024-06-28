class Solution {
    int n, m;

    // int solve(int i, int j, vector<vector<int>>& grid){
    //     if(i >= n || j >= m)
    //         return 1e9;
    //     if(i == n-1 && j == m-1)
    //         return grid[n-1][m-1];
        
    //     int right = grid[i][j] + solve(i, j + 1, grid);
    //     int down = grid[i][j] + solve(i + 1, j , grid);

    //     return min(right, down);
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int right = 1e9, down = 1e9;
                if(j > 0)
                    right = grid[i][j] + dp[i][j-1];
                if(i > 0)
                    down = grid[i][j] + dp[i-1][j];

                dp[i][j] = min(down, right);                    
            }
        }

        return dp[n-1][m-1];
    }
};