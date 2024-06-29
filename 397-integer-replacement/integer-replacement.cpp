class Solution {
    unordered_map<int, int> dp;
    
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
       
        if(dp.find(n) != dp.end())
            return dp[n];
        // int val = 1e9;
        if(n % 2){
            dp[n] = 1 + min(integerReplacement(n-1), 1 + integerReplacement(n/2 + 1));
        }else
            dp[n] = 1 + integerReplacement(n/2);
        
        return dp[n];
    }
};