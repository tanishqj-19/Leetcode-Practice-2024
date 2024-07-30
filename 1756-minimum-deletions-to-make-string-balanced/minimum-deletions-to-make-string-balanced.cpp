class Solution {
    int n;
public:
    int minimumDeletions(string s) {
        n = s.size();

        int b = 0; 
        vector<int> dp(n + 1 , 0);

        for(int i = 1; i<=n; i++){
            if(s[i-1] == 'a'){
                dp[i] = min(b, dp[i-1] + 1);
            }else{
                dp[i] = dp[i-1];
                b++; 
            }
        }


        return dp[n];
        
    }
};