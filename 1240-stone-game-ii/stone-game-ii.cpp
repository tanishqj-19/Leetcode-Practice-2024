class Solution {
    int n;
    int dp[101][101];
    int f(vector<int> &piles, int i, int M, int total){
        if(i >= n)
            return 0;
        if(dp[i][M] != -1)
            return dp[i][M];
        
        
        int m = min(2 * M + i, n);
        int sum = 0, taken = 0;
        for(int x = i ; x < m; x++){
            taken += piles[x];
            int newM = max(M, x - i + 1);

            sum = max(sum, total  - f(piles, x + 1, newM, total - taken));
        }

        return dp[i][M] = sum;    
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(dp, -1, sizeof(dp));


        int total = accumulate(piles.begin(), piles.end(), 0);

        return f(piles, 0, 1, total);



    }
};