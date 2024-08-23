class Solution {
    int n;
    int dp[101][101][2]; 
    
    int f(vector<int>& piles, int i, int M, bool aliceTurn) {
        if (i >= n) return 0; 
        
        if (dp[i][M][aliceTurn] != -1) return dp[i][M][aliceTurn]; 
        
        int m = min(2 * M + i, n);
        int result;
        int taken = 0;
        
        if (aliceTurn) {
            // Alice's turn, maximize her score.
            result = 0;
            for (int x = i; x < m; x++) {
                taken += piles[x];
                int newM = max(M, x - i + 1);
                result = max(result, taken + f(piles, x + 1, newM, false)); 
            }
        } else {
            
            result = INT_MAX;
            for (int x = i; x < m; x++) {
                taken += piles[x];
                int newM = max(M, x - i + 1);
                result = min(result, f(piles, x + 1, newM, true)); 
            }
        }

        return dp[i][M][aliceTurn] = result;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return f(piles, 0, 1, true);
    }
};
