class Solution {

    
    const int MOD = 1e9 + 7;

    long  solve(int n, int i, bool isGap, vector<vector<int>> &dp){
        if(i > n)
            return 0;
        if(i == n)
            return !isGap;
        if(dp[i][isGap] != -1)
            return dp[i][isGap];
        
        if(isGap){
            return dp[i][isGap] = (solve(n, i+1, false, dp) % MOD + solve(n, i + 1, true, dp) % MOD) % MOD;
        }

        return dp[i][isGap] = (solve(n, i+1, false, dp) + solve(n, i+2, false, dp) + (2 * solve(n, i+2, true, dp)) % MOD) % MOD;
        

    }
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(n, 0, false, dp);
    }
};
