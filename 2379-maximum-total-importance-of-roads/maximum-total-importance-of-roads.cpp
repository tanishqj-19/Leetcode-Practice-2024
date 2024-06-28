class Solution {

    
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;

        vector<long long> deg(n, 0);
        for(auto &x: roads){
            deg[x[0]]++;
            deg[x[1]]++;
        }

        sort(deg.begin(), deg.end());

        for(int x = 0; x <n ;x++){
            ans = ans + (long long) (deg[x] * (x + 1));
        }

        return ans;

    }
};