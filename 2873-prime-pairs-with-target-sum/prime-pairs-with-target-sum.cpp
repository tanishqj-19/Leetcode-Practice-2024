class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> sieve(n,true);

        sieve[0] = sieve[1] = false;

        for(int i = 2; i * i <= n; i++){
            if(sieve[i]){
                for(int j = i *i ; j<n; j+=i){
                    sieve[j] = false;
                }
            }
        }


        vector<vector<int>> ans;

        

        for(int i = 2; i<n; i++){
            if(sieve[i] && sieve[n-i]){
                
                    sieve[n-i] = false;
                    ans.push_back({i, n-i});
                
            }
        }

        return ans;
    }
};