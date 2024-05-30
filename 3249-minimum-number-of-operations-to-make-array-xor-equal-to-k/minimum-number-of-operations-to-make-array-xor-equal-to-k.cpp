class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int zor = 0;

        for(int i = 0; i<nums.size(); i++)
            zor ^= nums[i];
        
        int op = 0;
        for(int i = 0; i<32; i++){
            if((zor & (1 << i)) != (k & (1 << i)) ){
                op++;
            }
        }

        return op;
    }
};