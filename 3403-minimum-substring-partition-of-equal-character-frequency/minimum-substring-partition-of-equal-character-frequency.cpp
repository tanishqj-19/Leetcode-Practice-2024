class Solution {
    int n;
    int solve(string &s, int i, vector<int> &dp){

        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        vector<int> freq(26, 0);
        int ans = n;
        
        for(int j = i; j < n ; j++){
            char  c = s[j];
            freq[c - 'a']++;
            int maxC = 0, minC = n;
            
            for(int &k: freq){
                if(k > 0){
                    minC = min(minC, k);
                    maxC = max(maxC, k);
                }
            }


            if(maxC == minC){
                int next = 1 + solve(s, j + 1, dp);
                ans = min(ans, next);
            }
            

        }

        return dp[i] = ans;
    }
public:
    int minimumSubstringsInPartition(string s) {
        n = s.size();
        vector<int> dp(n, -1);
        return solve(s, 0, dp);
    }
};