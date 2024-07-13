class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0,  n = nums.size();
        int maxlen = 0, sum = 0;
        bool zero = false;
        while(j < n){
            if(nums[j] == 0 && !zero)
                zero = true;
            else if(nums[j] == 0 && zero){
                while(zero && i < n){
                    if(nums[i] == 0){
                        zero = false;
                    }
                    i++;
                }
                zero = (nums[j] == 0);
            }
            

           
            maxlen = max(maxlen, (j - i));

            j++;
        }

        return maxlen;
    }
};