class Solution {
    // int solve(int i, int j, string&s1, string &s2, vector<vector<int>> &dp){
    //     if(i < 0 || j < 0)
    //         return 0;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    
    //     if(s1[i] == s2[j])
    //         return dp[i][j] = 1 + solve(i-1,j-1, s1, s2, dp);
        
    //     return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j -1, s1, s2, dp));

    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(),n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i = 1; i<=n1; i++){
            for(int j = 1; j<=n2; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};