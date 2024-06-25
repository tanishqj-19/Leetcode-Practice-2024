class Solution {
    int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        if(n == 1 || n == 2)
            return n;
        if(n == 3)
            return 5;
        vector<long long > dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2, dp[3] = 5;

        for(int  i = 4; i<=n; i++){
            dp[i] = (dp[i-1] * 2 + dp[i-3]) % mod;
        }

        return dp[n];
    }
};