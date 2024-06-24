class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, flip = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] != flip){
                cnt++;
                flip = !flip;
            }
        }

        return cnt;
    }
};