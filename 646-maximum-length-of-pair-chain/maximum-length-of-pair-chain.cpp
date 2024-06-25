class Solution {
    int solve(vector<vector<int>>& pairs, int i, int prev, vector<vector<int>>& dp){
        if(i >= pairs.size())
            return 0;
        
        if(dp[i][prev + 1000] != -1)
            return dp[i][prev + 1000];
        
        int notPick  = solve(pairs, i+1, prev,dp);
        int pick  = 0;
        if(prev == 1001 || pairs[i][0] > prev)
            pick = 1 + solve(pairs, i + 1, pairs[i][1],dp);

        return dp[i][prev + 1000]  = max(pick, notPick);
    }

   
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1));

        return solve(pairs, 0, 1001, dp);
    }
};