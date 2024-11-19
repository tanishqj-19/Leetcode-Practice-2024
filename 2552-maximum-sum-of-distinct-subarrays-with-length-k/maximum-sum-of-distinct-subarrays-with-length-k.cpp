class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int i = 0, j = 0;
        long long sum = 0;
        long long maxSum = 0;
        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;

            while(i < j && mp.size() > k){
                mp[nums[i]]--;
                sum -= nums[i];

                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            if(mp.size() == k){
                while(j - i + 1 > k){
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
                if(mp.size() == k)
                    maxSum = max(maxSum, sum);
            }
            j++;

        }

        return maxSum;
    }
};