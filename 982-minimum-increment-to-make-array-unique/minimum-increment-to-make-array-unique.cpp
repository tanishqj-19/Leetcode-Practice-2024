class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int n = nums.size();
        int moves = 0;
        
        unordered_map<int, int> freq;
        int sz = 0;
        for(int &i: nums){
            freq[i]++;
            sz = max(sz, i);

        }
        sz += (n + 1);

        for(int i = 0; i<=sz; i++){
            
            if(freq[i] <= 1) continue;

            int dup = freq[i] -1;
            freq[i] = 1;
            freq[i + 1] += dup;
            moves += dup;
            
        }


        return moves;

    }
};