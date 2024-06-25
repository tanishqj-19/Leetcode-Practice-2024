class Solution {
    // int solve(vector<vector<int>>& pairs, int i, int prev, vector<vector<int>>& dp){
    //     if(i >= pairs.size())
    //         return 0;
        
    //     if(dp[i][prev + 1000] != -1)
    //         return dp[i][prev + 1000];
        
    //     int notPick  = solve(pairs, i+1, prev,dp);
    //     int pick  = 0;
    //     if(prev == 1001 || pairs[i][0] > prev)
    //         pick = 1 + solve(pairs, i + 1, pairs[i][1],dp);

    //     return dp[i][prev + 1000]  = max(pick, notPick);
    // }

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

   
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        
        int prev = -1e9, cnt = 0;
        for(int i = 0; i<n; i++){
            if(pairs[i][0] > prev){
                prev = pairs[i][1];
                cnt++;
            }
        }

        return cnt;
    }
};