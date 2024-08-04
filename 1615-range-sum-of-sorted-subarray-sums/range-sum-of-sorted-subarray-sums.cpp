#define ll long long

class Solution {

    const ll mod = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> sub;

        for(int i = 0; i<n; i++){
            ll sum = 0;
            for(int j = i; j<n; j++){
                sum = (sum + nums[j]) % mod;
                sub.push_back(sum);
            }
        }

        sort(sub.begin(), sub.end());

        ll ans = 0;

        left--; right--;
        while(left <= right){
            ans = (ans + sub[left++]) % mod;
        }

        return ans;
    }
};