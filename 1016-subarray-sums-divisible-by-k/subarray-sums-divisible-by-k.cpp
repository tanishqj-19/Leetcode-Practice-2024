class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;

        long long sum = 0;
        unordered_map<int, int> mp;
        mp[0 ] = 1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            
            int r = sum % k;

            if(r < 0)
                r += k;
            
                c += mp[r];
            
            mp[r]++;
        }



        return c;
    }
};