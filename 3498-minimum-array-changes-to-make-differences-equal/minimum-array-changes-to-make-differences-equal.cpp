class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, int> cnt;

        int i = 0, n = nums.size(), j = n-1;

        while(i < j){
            cnt[abs(nums[i++] - nums[j--])]++;
        }

        map<int, int> freqtoDiff;

        for(auto &x: cnt){
            if(freqtoDiff.find(x.second) == freqtoDiff.end())
                freqtoDiff[x.second] = x.first; 
        }
        int minChange = n;

        for(auto &it: freqtoDiff){
            int x = it.second;
            int op = 0;
            i = 0, j = n-1;

            while(i < j){
                if(abs(nums[i] - nums[j]) != x){
                    int mini = min(nums[i], nums[j]), maxi = max(nums[i], nums[j]);

                    if(k - mini >= x || maxi >= x){
                        op++;
                    }else{
                        op += 2;
                    }
                }
                i++; j--;
            }

            minChange = min(minChange, op);
        }

        return minChange;


    }
};