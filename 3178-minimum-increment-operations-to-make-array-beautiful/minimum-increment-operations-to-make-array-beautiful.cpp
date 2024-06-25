class Solution {
    #define ll long long
    int n;
    // ll solve(vector<int> &nums, int i, int k){
    //     if(i >= n)
    //         return 0;
        
        

    //     // ll notpick = solve(nums, i + 1, k);
    //     ll pick = 1e5, x = 1e5;
    //     // if(k - nums[i] >= 0) pick = k - nums[i];
    //     for(int j = i; j < n && j<i + 3; j++){
    //         int d = max(0, k - nums[j]);
    //         pick = d + min(x,)

    //     }


    //     return pick;
    // }
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();

        vector<ll> dp(n);
        for(int i = 0; i<3; i++)
            dp[i] = max(0, k - nums[i]);

        for(int i = 3; i<n; i++){
            dp[i] = max(0, k -nums[i]) + min(dp[i-1], min(dp[i-2], dp[i-3]));
        }
        
        

        return min(dp[n-3], min(dp[n-2], dp[n-1]));
    }
};