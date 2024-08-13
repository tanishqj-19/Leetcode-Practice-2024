class Solution {
    int dp[1001][1001];
    int f(vector<int> &nums, int k, int i){
        if(k == 0)
            return 0;
        
        if(k < 0 || i >= nums.size())
            return INT_MIN;
        if(dp[i][k] != -1)
            return dp[i][k];
        
        

        int notPick = f(nums, k, i + 1);
        int pick = 1 + f(nums, k - nums[i], i + 1);
        

        return dp[i][k] = max(pick, notPick);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = f(nums, target,  0);
        return ans < 0? -1: ans;
    }
};