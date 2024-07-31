class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        if(ns < np)
            return {};

        int i = 0, j = 0, k = np, win = np;
        int freq[26] = {0};

        for(auto &c: p) freq[c - 'a']++;

        for(; j < k; j++){
            freq[s[j] - 'a']--;

            if(freq[s[j]- 'a'] >= 0)
                win--;
            
        }
        vector<int> ans;

        if(win == 0)
            ans.push_back(0);
        
        while(j < ns){
            int idx = s[i] - 'a';

            if(freq[idx] >= 0)
                win++;
            freq[idx]++;
            i++;

            idx = s[j] - 'a';

            freq[idx]--;

            if(freq[idx] >= 0)
                win--;
            if(win == 0)
                ans.push_back(i);
            j++;
            
        }
        
        return ans;

    }
};