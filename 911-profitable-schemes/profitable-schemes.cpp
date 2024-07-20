class Solution {
    const int mod = 1e9 + 7;
    int sz;
    int dp[101][101][101];
    int solve(int i, int n, int minProfit, vector<int>& group, vector<int>& profit, int member){
        if(minProfit <= 0)
            minProfit = 0;
        if(i == sz){
            return minProfit <= 0 ? 1 : 0;
        }

        if(dp[i][member][minProfit] != -1)
            return dp[i][member][minProfit];

        int notPick = solve(i + 1, n, minProfit, group, profit, member);
        int pick = 0;

        if(group[i] + member <= n)
            pick = solve(i + 1, n, minProfit - profit[i], group, profit, member + group[i]);
        
        return dp[i][member][minProfit] = (pick + notPick) % mod;

        
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz = group.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, minProfit, group, profit, 0);
    }
};