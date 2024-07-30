class Solution {

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n3 = s3.size(), n2 = s2.size(), n1 = s1.size();

        if(n2 + n1 != n3)
            return false;
        if(n1 == 0 && n2 == 0 && n3 == 0)
            return true;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = 1;

        for(int i = 0; i<=n1; i++){
            for(int j = 0; j<=n2; j++){
                bool sol = false;
                int idx = i + j-1;
                if(i > 0){
                    if(s1[i-1] == s3[idx])
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }

                if(j > 0){
                    if(s2[j-1] == s3[idx])
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                }

            }
        }

        return dp[n1][n2];
    }

    
};