class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long i = 0, j = 0, currSum = 0;

        while(j < n){
            currSum += nums[j];

            
            if((j - i + 1) * nums[j] - currSum > k){
                currSum -= nums[i++];
            }
            j++;

           
        }

        return j - i;




       
        return 0;
    }
};