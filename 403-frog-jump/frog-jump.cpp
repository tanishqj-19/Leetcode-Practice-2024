class Solution {

    // bool solve(vector<int> &stones, int i, int n, int k, vector<vector<int >> &dp){
    //     if(i == n-1)
    //         return true;
    //     if( i >= n )
    //         return false;
    //     if(dp[i][k] != -1)
    //         return dp[i][k];
        
    //     bool  ans = false;

    //     for(int idx = i + 1; idx < n; idx++){
    //         if(stones[idx] - stones[i] > k + 1)
    //             break;
            
    //         for(int x = -1; x<2; x++){
    //             if(stones[idx] - stones[i] == k + x)
    //                 ans = solve(stones, idx, n, k + x, dp) || ans;

    //         }
    //     }

    //     return dp[i][k] = ans;


    // }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] > 1)
            return false;
        int n = stones.size();
        vector<vector<bool >> dp(n, vector<bool>(n+1, 0));
        dp[0][1] = true;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int d = stones[i] - stones[j];
                if( d> n || !dp[j][d])
                    continue;
                
                if(i == n-1)
                    return true;
                
                dp[i][d] = true;

                if(d - 1 >= 0) dp[i][d-1] = true;
                if(d + 1 <= n) dp[i][d + 1] = true;

                
                
            }
        }

        return false;

        
    }
};