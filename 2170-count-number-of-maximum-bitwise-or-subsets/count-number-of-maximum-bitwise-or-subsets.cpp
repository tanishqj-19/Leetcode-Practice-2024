class Solution {
    int n;
    int count = 0;
    int maxOr = 0;
    void solve(vector<int> &nums, int idx, int curr){

        if(idx == n){
            if(curr == maxOr)
                count++;
            return;
        }
       
        solve(nums, idx + 1, curr | nums[idx]);

        solve(nums, idx + 1, curr);
        
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        for(int &i: nums) maxOr |= i;

        solve(nums, 0, 0);

        

        return count;

    }
};