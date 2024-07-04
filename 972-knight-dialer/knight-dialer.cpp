class Solution {
    const int  mod = 1e9 + 7;
    vector<vector<int>> possibleChoice;
    
public:
    int knightDialer(int n) {
        possibleChoice = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        vector<vector<int>> dp(n, vector<int>(10, 0));

        for(int i = 0; i<10; i++) dp[0][i] = 1;
        int ans =  0;
        

            for(int remain = 1; remain < n; remain++){
                for(int i = 0; i<10; i++){
                    int val = 0;
                    for(auto &next: possibleChoice[i]){
                        val  = (val + dp[remain-1][next]) % mod;
                    }

                    dp[remain][i] = val;

                }
            
            } 

            for(int i = 0; i<10; i++){
                ans = (ans + dp[n-1][i]) % mod;
            }   
        return ans;
    }
};