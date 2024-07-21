class Solution {
    int solve(vector<int> &slices, int i, int numSlice, int end, vector<vector<int>> &dp){
        if(numSlice == 0 || i > end)
            return 0;
        if(dp[i][numSlice] != -1)
            return dp[i][numSlice];
        
        int pick = slices[i] + solve(slices, i + 2, numSlice-1, end, dp);
        int notPick = solve(slices, i + 1, numSlice, end, dp);

        return dp[i][numSlice] = max(pick, notPick);

        
    }
public:
    int rob(vector<int>& slices) {
        
        int n = slices.size();
        if(n == 1)
            return slices[0];  

        vector<vector<int>> dp1(n , vector<int>(n+1, -1));
        int first = solve(slices, 0, n, n-2, dp1);
        vector<vector<int>> dp2(n, vector<int>(n+1, -1));

        int second  = solve(slices, 1, n, n-1, dp2);

        return max(first, second);
    }
};