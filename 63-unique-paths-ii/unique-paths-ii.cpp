class Solution {

    int n,m;
    // int solve(int i, int j,vector<vector<int>> &grid, vector<vector<int>> &dp){
    //     if(i >= n || j >= m || grid[i][j])
    //         return 0;
    //     if(i == n-1 && j == m-1)
    //         return 1;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     int left = solve(i , j + 1, grid, dp);
    //     int down = solve(i + 1, j , grid, dp);

    //     return dp[i][j] = left + down;
    // }
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);
        // prev[0] = (grid[0][0] == 0);

        for(int i = 0; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j<m; j++){
                // int left = 0, right = 0;
                if(grid[i][j]) continue;
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }

                if(i > 0)
                    curr[j] += prev[j];
                if(j > 0)
                    curr[j] += curr[j-1];

            }
            prev = curr;
        }

        
        return prev[m-1];


    }
};