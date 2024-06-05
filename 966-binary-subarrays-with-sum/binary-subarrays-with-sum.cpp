class Solution {
    int helper(vector<int> &nums, int k){
        if(k < 0)
            return 0;
        int sum = 0, l = 0, r = 0, n = nums.size();
        int total {0};
        for(; r < n; r++){
            sum += nums[r];

            while(sum > k  && l < n){
                sum -= nums[l++];
            }
            total += (r - l + 1);
        }

        return total;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};