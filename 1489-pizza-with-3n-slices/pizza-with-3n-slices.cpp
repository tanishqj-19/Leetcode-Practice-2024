class Solution {
    
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        vector<vector<int>> dp1(n + 1 , vector<int>(n/3 + 1, 0));

        for(int i = n-2; i>=0; i--){
            for(int j = 1; j <= n/3; j++){
                int notPick = dp1[i+1][j];
                int pick = dp1[i+2][j-1] + slices[i]; 

                dp1[i][j] = max(pick, notPick);
            }
        }
        vector<vector<int>> dp2(n + 2, vector<int>(n/3 + 1, 0));

        for(int i = n-1; i>=1; i--){
            for(int j =1; j<= n/3; j++){
                int notPick = dp2[i+1][j];
                int pick = dp2[i+2][j-1] + slices[i]; 

                dp2[i][j] = max(pick, notPick);
            }
        }

        return max(dp1[0][n/3],dp2[1][n/3]);


    }
};