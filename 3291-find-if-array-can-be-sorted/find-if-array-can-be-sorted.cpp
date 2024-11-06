class Solution {

    
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();


        for(int i = 0; i <n; i++){
            int minIdx = i;
            int minVal, currVal;
            for(int j = i + 1; j<n; j++){
                if(nums[j] < nums[minIdx]){
                    minIdx = j;
                    break;
                }
            }

            minVal = __builtin_popcount(nums[minIdx]);
            currVal = __builtin_popcount(nums[i]);

            if(currVal != minVal)
                return false;
            swap(nums[minIdx], nums[i]);
        }
        return true;
    }
};