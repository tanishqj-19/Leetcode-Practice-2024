class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxlen = 0;
        unordered_map<char, int> mp;
        for(auto &c: s){
            mp[c]++;
        }

        for(auto &x: mp){
            char c = x.first;
            int i = 0, j = 0, cnt = 0;

            for(; j < n; j++){
                if(s[j] != c){
                    cnt++;
                }
                while(cnt > k){
                    if(s[i] != c){
                        cnt--;
                    }
                    i++;
                }
                maxlen = max(maxlen, j - i + 1);
                
            }
        }

        return maxlen;
    }
};