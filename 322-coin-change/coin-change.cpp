class Solution {

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(i < 0)
            return 1e9;
        if(i == 0){
            
            if(amount % coins[i] == 0)
                return amount/coins[i];
            else
                return 1e9;
        }

        if(amount == 0)
            return 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int notPick = solve(i -1, coins, amount, dp), pick = 1e9;

        if(coins[i] <= amount){
            pick = 1 + solve(i, coins, amount-coins[i], dp);
        }

        return dp[i][amount] = min(pick, notPick);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n-1, coins, amount, dp);


        return ans == 1e9 ? -1 : ans;
    }
};