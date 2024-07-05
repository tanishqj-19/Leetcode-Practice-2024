class Solution {
   
    // int mod = 1e9 + 7;
    bool valid(int i, int j, int n){
        return (i >= 0 && j >= 0 && j < n && i < n);
    }
    
    int dir[8][2] = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};
    double solve(int i, int j, int n, int k,  vector<vector<vector<double>>> &dp){
        
        if(!valid(i, j, n))
            return 0;

        if (k == 0){
            return 1.0;
        }
       
        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        
        double x = 0;
        for(int z = 0; z<8; z++){
            x += solve(i + dir[z][0], j + dir[z][1], n, k-1, dp);
        }
        
        double ans = (double) ( x / 8.0);

        return dp[i][j][k] = ans;
        
        
    }


public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));

        return solve(row, column, n, k, dp);

        
    }
};