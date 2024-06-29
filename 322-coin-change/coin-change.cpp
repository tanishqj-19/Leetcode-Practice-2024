class Solution {

    // int solve(int i, vector<int>& coins, int amount, vector<vector<int>>&dp){
    //     if(i < 0)
    //         return 1e9;
    //     if(i == 0){
            
    //         if(amount % coins[i] == 0)
    //             return amount/coins[i];
    //         else
    //             return 1e9;
    //     }

    //     if(amount == 0)
    //         return 0;
    //     if(dp[i][amount] != -1)
    //         return dp[i][amount];
        
    //     int notPick = solve(i -1, coins, amount, dp), pick = 1e9;

    //     if(coins[i] <= amount){
    //         pick = 1 + solve(i, coins, amount-coins[i], dp);
    //     }

    //     return dp[i][amount] = min(pick, notPick);

    // }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        // int ans = solve(n-1, coins, amount, dp);

        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0)
                dp[0][i] = i/coins[0];
            else
                dp[0][i] = 1e9;
        }
        
        for(int i = 0; i<n; i++) dp[i][0] = 0;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                int notPick = dp[i-1][j], pick = 1e9;

                if(coins[i] <= j){
                    pick = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(pick, notPick);
            }
        }


        return dp[n-1][amount] == 1e9 ? -1: dp[n-1][amount];



        // return ans == 1e9 ? -1 : ans;
    }
};