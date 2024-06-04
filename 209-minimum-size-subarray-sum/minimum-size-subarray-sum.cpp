class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), i = 0, j = 0;
        int sum = 0, minlen = n + 1;
        for(; j <  n; j++){
            sum += nums[j];

            while(sum >= target){
                minlen = min(minlen, j - i + 1);
                sum -= nums[i++];
            }
        }

        return minlen == n + 1 ? 0 : minlen;
    }
};