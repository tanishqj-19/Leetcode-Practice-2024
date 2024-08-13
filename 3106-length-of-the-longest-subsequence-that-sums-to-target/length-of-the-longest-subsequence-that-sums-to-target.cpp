class Solution {
    
    
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(target + 1, INT_MIN);
        

        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int k = target; k >= nums[i]; k--){
                dp[k] = max(dp[k], 1 + dp[k-nums[i]]);
            }
        }

        return dp[target] <= 0 ? -1 : dp[target];
    }
};