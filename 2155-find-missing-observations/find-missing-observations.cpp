#define ll int
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int total = mean * (m + n);

        for(int &i: rolls)
            total -= i;
      
        if(total < n || total > 6 * n)
            return {};
        
        int val = total / n;
        int remain = total % n;

        vector<int> ans(n, val);

        int j = 0;
        while(j < remain){
            ans[j]++;
            j++;
        }

        return ans;
        
    }
};