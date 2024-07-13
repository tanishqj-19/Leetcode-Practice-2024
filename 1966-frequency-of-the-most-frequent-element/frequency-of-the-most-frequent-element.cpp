class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long i = 0, j = 0, currSum = 0, maxfreq = 1;

        while(j < n){
            currSum += nums[j];

            
            while(i < n && (j - i + 1) * nums[j] - currSum > k){
                currSum -= nums[i++];
            }

            maxfreq = max(maxfreq, (j - i + 1));
            j++;
        }

        return maxfreq;




       
        return 0;
    }
};