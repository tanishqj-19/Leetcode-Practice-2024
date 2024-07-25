class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        
        // Base case: There's one way to achieve sum 0 with no elements (by doing nothing)
        dp[0][1000] = 1;
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int sum = -1000; sum <= 1000; ++sum) {
                if (dp[i-1][sum + 1000] != 0) {
                    dp[i][sum + nums[i-1] + 1000] += dp[i-1][sum + 1000];
                    dp[i][sum - nums[i-1] + 1000] += dp[i-1][sum + 1000];
                }
            }
        }
        
        // The result is the number of ways to get to the target sum
        return target > 1000 || target < -1000 ? 0 : dp[n][target + 1000];
    }
};
