class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> freq;

        int n  = nums.size();

        if(n % k != 0)  return false;

        for(int i = 0; i<n; i++) freq[nums[i]]++;

        while(!freq.empty()){
            int curr = freq.begin()->first;
            
            for(int i = 0; i < k; i++){
                if(freq[curr  + i] == 0)
                    return false;

                freq[curr + i]--;
                if(freq[curr + i] == 0 )
                    freq.erase(curr + i);
            }

        }

        return true;

        
    }
};