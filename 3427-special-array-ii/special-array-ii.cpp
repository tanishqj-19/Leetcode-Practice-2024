class Solution {
    bool isOdd(int x){
        return x & (1) != 0;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> parity;
        parity.push_back(0);

        for(int i =1; i<n; i++){
            if(isOdd(nums[i]) == isOdd(nums[i-1]))
                parity.push_back(parity.back() + 1);
            else
                parity.push_back(parity.back() + 0);




        }

        vector<bool>ans;
        for(auto &q: queries){
            ans.push_back(parity[q[0]] == parity[q[1]]);
        }

        return ans;
        
    }
};