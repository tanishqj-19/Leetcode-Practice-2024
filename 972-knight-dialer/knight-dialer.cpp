class Solution {
    const long long  mod = 1e9 + 7;
    vector<vector<int>> possibleChoice;
    int solve(int n, int sq, vector<vector<int>> &dp){
        if(n == 0)
            return 1;
        if(dp[n][sq] != -1)
            return dp[n][sq];
        int ans = 0;
        for(auto &next: possibleChoice[sq]){
            ans  = (ans + solve(n-1, next, dp)) % mod;
        }

        return dp[n][sq] = ans;
    }
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
        vector<vector<int>> dp(n, vector<int>(10, -1));
        int ans =  0;
        for(int i = 0; i<10; i++){
            ans = (ans + solve(n-1, i, dp)) % mod;
        }     
        return ans;
    }
};