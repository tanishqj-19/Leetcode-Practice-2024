class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0,  n = nums.size();
        // int maxlen = 0;
        int zero = 0;
        while(j < n){
            
            if(nums[j] == 0)
                zero++;
            
            if(zero > 1){
                if(nums[i] == 0)
                    zero--;
                i++;
            }

           
            // maxlen = max(maxlen, (j - i));

            j++;
        }

        return j -i -1;
    }
};