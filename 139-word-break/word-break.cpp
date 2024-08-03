class Solution {
    unordered_set<string> st;
    int dp[301];
    bool check(string &s, int i, int n){
        if(i >= n){
            return true;
        }
        if(dp[i] != -1)
            return dp[i];
        for(int idx = 1; i + idx <= n; idx++){
            string temp = s.substr(i, idx);
            if(st.find(temp) != st.end()){
                bool next = check(s, i + idx, n);
                if(next)
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memset(dp, - 1, sizeof(dp));
        for(string &c: wordDict){
            st.insert(c);
        }
        return check(s,0,n);
    }
};