class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;

        if(n <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int killAllSmallest = nums[n-1] - nums[3];
        int killAllLargest = nums[n-4] - nums[0];
        int killOneSmallTwoLarge = nums[n-3] - nums[1];
        int killTwoSmallOneLarge = nums[n-2] - nums[2];


        return min(killAllSmallest, min(killAllLargest, min(killOneSmallTwoLarge, killTwoSmallOneLarge)));
    }
};