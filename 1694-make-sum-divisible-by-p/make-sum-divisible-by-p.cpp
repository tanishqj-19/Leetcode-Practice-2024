

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int r = 0,n = nums.size();

        for(auto &i: nums) 
            r = (r + i) % p;

        if(r == 0)
            return 0;

        int curr = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
       
        int ans = n;

        for(int i = 0; i<n; i++){
            curr  = (curr + nums[i]) % p;
            int need = (curr - r + p) % p;
            if(mp.find(need) != mp.end())
                ans = min(ans, i - mp[need]);
            
            mp[curr] = i;

        }

        return ans < n ? ans : -1;
    }
};