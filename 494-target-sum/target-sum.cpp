class Solution {
    int solve(int i, vector<int> &nums, int x, int target,vector<vector<int>> &dp){
        if(i < 0 && x == target)
            return 1;
        if(i < 0)
            return 0;
        if(dp[i][x + 1000]  != -1)
            return dp[i][x + 1000];
        
        
        
        int neg =  solve(i -1, nums, x - nums[i], target, dp);
        int pos = solve(i -1, nums, x + nums[i], target, dp);

        return dp[i][x + 1000] =  neg + pos;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1));
        return solve(n-1, nums, 0, target, dp);
    }
};