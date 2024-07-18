class Solution {
    vector<int> values;

    // int solve(int i, int num, vector<vector<int>> &dp){
        
    //     if(i < 0)
    //         return 1e9;
    //     if(i == 0){
    //         if(num % values[i] == 0)
    //             return num / values[i];
    //         return 1e9;
    //     }
    //     if(dp[i][num] != -1)
    //         return dp[i][num];
        
    //     int notPick = solve(i-1, num, dp);

    //     int pick = 1e9;
    //     if(values[i] <= num){
    //         pick = 1 + solve(i, num-values[i], dp);
    //     }

    //     return dp[i][num] =  min(pick, notPick);
    // }

public:
    int minimumNumbers(int num, int k) {
        
        if(num == 0)
            return 0;
        for(int  i = 1 ; i<= num; i++){
            if(i % 10 == k)
                values.push_back(i); // in sorted order
        }
        if(values.empty())
            return -1;

        int n = values.size();

        vector<int> curr(num + 1, 1e9), prev(num + 1,  1e9);
        for(int i=0; i<=num; i++){
            if(i % values[0] == 0)
                prev[i] = i / values[0];
        }

        

        for(int i = 1; i<n; i++){
            for(int val = 0; val <= num; val++){
                int notPick = prev[val], pick = 1e9;
                if(values[i] <= val){
                    pick = 1 + curr[val-values[i]];
                }

                curr[val] = min(pick, notPick);
            }
            prev = curr;
        }

        // int ans = solve(n-1, num, dp);

        return prev[num] == 1e9? -1:  prev[num];


    }
};