class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, len = 1;

        while(j < n){
            
            if(nums[j] <= nums[j-1]){
                i = j;
            }
            len = max(len, j -i  + 1);
            j++;
        }

        return len;
    }
};