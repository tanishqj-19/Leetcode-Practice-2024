class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int i = 0, j = 0;
        long long maxSum = 0, sum = 0;
        while(j < n){
            
            int lastIdx = mp.count(nums[j]) ? mp[nums[j]] : -1;

            while(i <= lastIdx || j - i + 1 > k){
                sum -= nums[i++];
            }
            mp[nums[j]] = j;
            sum += nums[j];

            if(j - i + 1 == k){
                maxSum = max(maxSum, sum);
            }
            j++;

        }

        return maxSum;
    }
};