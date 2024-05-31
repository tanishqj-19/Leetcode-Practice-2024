class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int zor = 0;

        for(int &i: nums) zor ^= i;

        
        int firstSetBit = 0;

        for(int j = 0; j<32; j++){
            if( (zor & (1 << j)) != 0){
                firstSetBit = j;
                break;
            }
        }
        
        int oneb = 0, twob = 0;
        for(int  i = 0; i<n; i++){
            if(nums[i] & (1 << firstSetBit)){
                oneb ^= nums[i];
            }else{
                twob ^= nums[i];
            }
        }



        return {oneb , twob};
    }
};