class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int> arr {0};

        for(int i = 1; i<nums.size(); i++){
            int f = (nums[i] % 2 == nums[i-1] % 2);
            arr.push_back(arr.back() + f);
        } 
        vector<bool> special;
        for(auto &v: queries){
            special.push_back(arr[v[0]] == arr[v[1]]);
        }

        return special;
    }
};