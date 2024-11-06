class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();


        int maxi = nums[0], mini = nums[0];
        int count = __builtin_popcount(nums[0]);
        int maxPrev = INT_MIN;

        for(int i = 1; i<n; i++){

            int curr = __builtin_popcount(nums[i]);

            if(curr == count){
                maxi = max(maxi, nums[i]),
                mini = min(mini, nums[i]);

            }else{
                if(mini < maxPrev){
                    return false;
                }


                maxPrev = maxi;
                maxi = mini = nums[i];
                count = curr;
            }
        }

        if(mini < maxPrev)
            return false;

        return true;
    }
};