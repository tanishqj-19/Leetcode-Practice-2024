class Solution {
    bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        if(i < 0 && j < 0)
            return true;
        if(i < 0 && j >= 0)
            return false;
        if(j < 0 && i >= 0){
            for(int idx = 0; idx <= i; idx++){
                if(p[idx] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        if(p[i] == '*')
            return dp[i][j]  = solve(i-1, j, p, s, dp) || solve(i, j-1, p, s, dp);
        return false;
        
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, p, s, dp);
    }
};