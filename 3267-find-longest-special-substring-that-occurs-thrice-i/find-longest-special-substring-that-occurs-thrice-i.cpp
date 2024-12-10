class Solution {
    bool allSame(string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] != s[0])
            return false;
 
    return true;
}
public:
    int maximumLength(string &s) {
        unordered_map<string, int> mp;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            for(int sz=1; sz<= n-i; sz++){
                string sub = s.substr(i, sz);
                
                mp[sub]++;
                
            }
        }
        
        int ans = -1;
        
        for(auto word: mp){
            if(word.second >= 3 && allSame(word.first)){
                n = word.first.size();
                ans = max(n, ans);
                
            }
        }
                
        
        
        return ans;
    }
};