#define ll int

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;

        int n = nums.size();

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j <i; j++){
                ll pro = (ll) nums[i] *(ll) nums[j];
                ans += 8 * freq[pro];
                freq[pro]++;
            }
        }

        return ans;
    }
};