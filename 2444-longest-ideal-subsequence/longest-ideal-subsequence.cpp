class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        int ans = 1;
        for(char &c: s){
            int i = c - 'a';
            dp[i] += 1;
            for(int j = max(i - k, 0); j <= min(i + k, 25); j++){
                if(i == j) continue;
                dp[i]  = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }

        return ans;

    }
};