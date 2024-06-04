class Solution {

    int helper(vector<int> &nums, int k){
        int l = 0, n = nums.size(), r = 0, cnt = 0;
        int total = 0;
        while(r < n){
            cnt += (nums[r] % 2);

            while(cnt > k){
                cnt -= (nums[l] % 2);
                l++;
            }

            total += (r - l + 1);
            r++;
            
        }

        return total;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};