class Solution {
    int n;
    int solve(int i, vector<int> &prices, int canBuy, int k, vector<vector<vector<int>>>& dp){
        if(i == n || k == 0){
            return 0;
        }

        if(dp[i][canBuy][k] != -1 )
            return dp[i][canBuy][k];

        int op1 = 0, op2 =0 ;
        if(canBuy){
            op1 = -prices[i] + solve(i + 1, prices, 0, k, dp);
            op2 = solve(i + 1, prices, canBuy, k, dp);
        }else{
            op1 = prices[i] + solve(i + 1, prices, 1, k-1, dp);
            op2 = solve(i + 1, prices, 0, k, dp);
        }
        
        return dp[i][canBuy][k] = max(op1, op2);
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2, vector<int>(3, -1)));


        return solve(0, prices, 1, 2, dp);
    }
};