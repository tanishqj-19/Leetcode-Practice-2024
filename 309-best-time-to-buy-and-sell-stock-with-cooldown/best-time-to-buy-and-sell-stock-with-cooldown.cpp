class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2,vector<int>(2, 0));
        
        for(int i = n-1; i>= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                
                    int op1 = 0, op2 =0 ;
                    if(canBuy){
                        op1 = -prices[i] + dp[i + 1][0];
                        op2 = dp[i+1][1];
                    }else{
                        op1 = prices[i] + dp[i+2][1];
                        op2 = dp[i+1][0];
                    }

                    dp[i][canBuy] = max(op1, op2);
                
            }
        }


        return dp[0][1];
    }
};