class Solution {
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> count;

        for(int &n: nums) count[n]++;

        sort(nums.begin(), nums.end(), [&](int a, int b){
            return count[a] == count[b] ?  a > b : count[a] < count[b];
        });

       
        return nums;





    }
};