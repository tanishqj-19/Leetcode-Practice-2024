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
        
        vector<vector<long long>> dp(n + 2, vector<long long>(2, 0));

        dp[1] = {1, 1}; dp[2] = {2, 2};

        for(int i = 3; i<=n; i++){
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2 * dp[i-2][1]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
        return dp[n][0];
    }
};
