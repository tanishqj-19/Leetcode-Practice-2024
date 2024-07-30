class Solution {

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n3 = s3.size(), n2 = s2.size(), n1 = s1.size();

        if(n2 + n1 != n3)
            return false;
        
        if(n1 < n2){
            return isInterleave(s2, s1, s3);
        }

        vector<bool> dp(n2 + 1, false);
        dp[0] = true;

        for(int j = 1; j <= n2; j++){
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }

        for(int i = 1; i<=n1; i++){
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for(int j = 1; j<=n2; j++){
                int idx = i + j-1;
                bool one = false, two = false;

                if(s1[i-1] == s3[idx])
                    one  = dp[j];
                if(s2[j-1] == s3[idx])
                    two = dp[j-1];
                dp[j] = one || two;
            }
        }

        return dp[n2];
    }

    
};