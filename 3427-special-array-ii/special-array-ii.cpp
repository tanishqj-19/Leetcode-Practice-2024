class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> parity;
        parity.push_back(0);

        for(int i =1; i<n; i++){
            int val = (nums[i] % 2 == nums[i-1] % 2);

            parity.push_back(parity.back() + val);
        }

        vector<bool>ans;
        for(auto &q: queries){
            ans.push_back(parity[q[0]] == parity[q[1]]);
        }

        return ans;
        
    }
};