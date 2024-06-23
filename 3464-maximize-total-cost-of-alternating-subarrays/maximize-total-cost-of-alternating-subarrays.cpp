#define ll long long

class Solution {

    ll solve(vector<int> &nums, int i, bool neg, vector<vector<ll>> &dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[i][neg] != -1e9)
            return dp[i][neg];
        
        ll negTake  = -1e8, take = -1e8;

        if(neg){
            negTake = (-nums[i]) + solve(nums, i + 1, false, dp);
        }

        take = (nums[i]) + solve(nums, i + 1, true, dp);

        return dp[i][neg] = max(take, negTake);


    }
    
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();

        vector<vector<ll>> dp(n, vector<ll> (2, -1e9));
        int i = 1; bool neg = true;
        return (ll) nums[0] + solve(nums, i, neg, dp);
    }
};