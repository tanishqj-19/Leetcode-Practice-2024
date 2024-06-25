class Solution {
    // int solve(vector<vector<int>>& pairs, int i, int prev, vector<vector<int>>& dp){
    //     if(i >= pairs.size())
    //         return 0;
        
    //     if(dp[i][prev + 1000] != -1)
    //         return dp[i][prev + 1000];
        
    //     int notPick  = solve(pairs, i+1, prev,dp);
    //     int pick  = 0;
    //     if(prev == 1001 || pairs[i][0] > prev)
    //         pick = 1 + solve(pairs, i + 1, pairs[i][1],dp);

    //     return dp[i][prev + 1000]  = max(pick, notPick);
    // }

    

   
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        
        vector<int> dp(n, 1);   

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i;j++){
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            // cnt = max(dp[i], cnt);
        }
        return dp[n-1];
    }
};