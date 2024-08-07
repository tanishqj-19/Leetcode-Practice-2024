class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &i : nums){
            mp[i]++;
        }
        vector<int> ans;
        for(int &i: nums){
            if(mp.find(i-1) == mp.end() && mp.find(i + 1) == mp.end() && mp[i] == 1)
                ans.push_back(i);
        }

        return ans;
    }
};