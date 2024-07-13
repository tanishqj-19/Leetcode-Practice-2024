class Solution {

    void count_sort(vector<int> &nums){
        int sz = 0;

        for(int &i: nums) sz = max(sz, i);

        vector<int>count(sz + 1, 0);

        for(int &i: nums) count[i]++;

        int idx = 0;

        for(int i = 0; i<=sz; i++){
            while(count[i] > 0){
                nums[idx++] = i;
                count[i]--;
            }
            
        } 

        return;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        count_sort(nums);
        int n = nums.size();

        long long i = 0, j = 0, currSum = 0;

        while(j < n){
            currSum += nums[j];

            
            if((j - i + 1) * nums[j] - currSum > k){
                currSum -= nums[i++];
            }
            j++;

           
        }

        return j - i;;
    }
};