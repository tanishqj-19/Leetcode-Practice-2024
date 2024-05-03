class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int  i = 0, j = 0, n = nums.size();


        int maxSum = 0;
        unordered_map<int, int> track;

        int sum = 0;
        while(i < n && j < n){

            if(track.find(nums[i]) == track.end()){
                sum += nums[i];
                maxSum = max(maxSum, sum);
                track[nums[i]] = i;
                i++;
            }else{
                sum -= nums[j];
                track.erase(nums[j]);
                j++;
            }
            
        }

        return maxSum;
    }
};