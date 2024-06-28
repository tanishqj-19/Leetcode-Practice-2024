class Solution {
    #define ll long long
    ll n ;
    map<int, int> freq;
    
    ll solve(int i, vector<int> &power, vector<ll> &dp){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        ll notPick = solve(i + 1, power, dp), take = 0;

        int idx = i+1;
        while(idx < n && power[idx] - power[i] <= 2)
            idx++;
        
        take = ( (ll) freq[power[i]] * (ll) power[i] ) + solve(idx, power, dp);

        return dp[i] = max(take, notPick);


    
        
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
    
        for(int &x: power)
            freq[x]++;
        vector<int> uni;
        for(auto &x: freq) uni.push_back(x.first);
        
        n = uni.size();

        vector<ll> dp(n, -1);
        
        return solve(0, uni, dp);
    }
};