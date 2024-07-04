class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2, vector<int>(cap+1, 0)));

        for(int i = n-1; i>= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int k = 1; k<= cap; k++){
                    int op1 = 0, op2 =0 ;
                    if(canBuy){
                        op1 = -prices[i] + dp[i + 1][0][k];
                        op2 = dp[i+1][1][k];
                    }else{
                        op1 = prices[i] + dp[i+1][1][k-1];
                        op2 = dp[i+1][0][k];
                    }

                    dp[i][canBuy][k] = max(op1, op2);
                }
            }
        }


        return dp[0][1][cap];
    }
};