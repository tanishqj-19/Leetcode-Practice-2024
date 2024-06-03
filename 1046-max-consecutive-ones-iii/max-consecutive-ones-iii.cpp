class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), zero = 0, cnt = 0, l = 0, r = 0;
        int maxlen = 0;

        while(r < n){
            
            if(nums[r] == 0){
                cnt++;
            }

            while(cnt > k && l < n){
                cnt -= (nums[l] == 0);
                l++;
            }
                
            
            maxlen = max(maxlen, r - l + 1);
            r++;

        }

        return maxlen;
    }
};