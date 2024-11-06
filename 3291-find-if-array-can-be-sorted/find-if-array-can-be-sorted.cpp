class Solution {

    
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <n; i++){
            int minVal, currVal;
            for(int j = 0; j<n-i-1; j++){
                if(nums[j] <= nums[j + 1]){
                    continue;
                }else{
                    minVal = __builtin_popcount(nums[j + 1]);
                    currVal = __builtin_popcount(nums[j]);

                    if(minVal != currVal)
                        return false;
                    swap(nums[j], nums[j + 1]);
                }
            }

        }
        return true;
    }
};