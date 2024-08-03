class Solution {
    
    bool dp[301];
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        

        for(int i =0; i<n; i++){
            for(auto &word: wordDict){
                int sz = word.size();
                if(i < sz - 1)
                    continue;

                if(i == sz - 1 || dp[i - sz]){
                    if(s.substr(i -sz  + 1, sz) == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }


        return dp[n-1];
    }
};