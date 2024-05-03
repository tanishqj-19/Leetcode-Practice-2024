class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m  = t.size();

        int  i = 0, j  = 0, len = n + 1, begin = 0;
        unordered_map<char, int> count;
        for(char &x: t) count[x]++;

        while(i < n){

            if(count[s[i]] > 0){
                m--;
            }
            count[s[i]]--;
            i++;

            while(m == 0){
                if(i - j < len){
                    len = i - j;
                    begin = j;
                }

                if(count[s[j]] == 0){
                    m++;
                }
                count[s[j]]++;

                j++;
            }
            
        }


        return len == (n + 1) ? "" : s.substr(begin,  len);
    }
};