class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int zor = 0;

        for(auto & x: nums) zor ^= x;

        return zor;
    }
};