class Solution {
    const int mod = 1e9 + 7;
    int sz;
    
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;

        for(int i = 0; i<sz; i++){
            int grp = group[i], curr_p = profit[i];
            for(int j = n; j>=grp; j--){
                for(int p = minProfit; p >= 0; p--){
                    dp[j][p] = (dp[j][p] + dp[j - grp][max(0, p - curr_p)]) % mod;
                }
            }
        }

        int totalSchemes = 0;
        for (int j = 0; j <= n; ++j) {
            totalSchemes = (totalSchemes + dp[j][minProfit]) % mod;
        }

        return totalSchemes;
    }
};