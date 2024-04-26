class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> last(n, 1e9);

        last = grid[0];

        

        for(int i=1; i<n; i++){
            vector<int> curr(n);

            for(int j = 0; j<n; j++){
                int ans = INT_MAX;

                for(int k = 0; k<n; k++){
                    if(j == k) continue;

                    ans = min(ans, grid[i][j] + last[k]);

                }
                curr[j] = ans;
            }

            last = curr;
        
        }

        int res = 1e9;

        for(auto &x: last) res = min(res, x);

        return res;
    }
};