class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();

        long long count = 0;
        map<int, int> freq;
        while(j < n){
            freq[nums[j]]++;
            
            while(i < n && prev(freq.end())->first - freq.begin()-> first > 2){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            
            count += (j - i + 1);
            
            j++;
        }

        return count;
    }
};