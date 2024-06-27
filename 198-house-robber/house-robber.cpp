class Solution {
    int n;
    vector<int> dp;
    int solve(vector<int> &nums, int i){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int notPick = solve(nums, i +1);

        int pick = nums[i] + solve(nums, i + 2);

        return dp[i] =  max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
         n = nums.size();
        // if(n == 1)
        //     return nums[0];
        // if(n == 2)
        //     return max(nums[0],)
        dp.resize(n + 1, -1);
        // dp[0] = nums[0], dp[1] = nums[1];
        // for(int i =2; i<n; i++){
        //     int notPick = dp[i-1];
        //     int pick = nums[i] + dp[i-2];
        //     dp[i] = max(pick, notPick);
        // }
        // return dp[n-1];
        return solve(nums, 0);
    }
};