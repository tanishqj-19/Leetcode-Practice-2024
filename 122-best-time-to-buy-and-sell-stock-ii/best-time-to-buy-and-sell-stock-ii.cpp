class Solution {

    int solve(vector<int> &cost, int i, int buy, vector<vector<int>> &dp){
        if(i == cost.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int take = 0, nottake = 0;

        if(buy == 1){
            take = max(-cost[i] + solve(cost, i+1, 0, dp), solve(cost, i+1, 1, dp));
        }else{
            nottake = max(cost[i] + solve(cost, i+1, 1, dp), solve(cost, i+1,0, dp));
        }

        return dp[i][buy] =  max(take, nottake);
    }
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        

        return solve(prices, 0, 1, dp);
    }
};