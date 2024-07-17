class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        unordered_map<char, int> count;
        int left = 0;
        int maxlen = 0;
        for(int i = 0; i<n; i++){
            
            
            if(count.find(s[i]) != count.end()){
                left = max(left, count[s[i]] + 1);
            }
            maxlen = max(maxlen, i - left + 1);

            count[s[i]] = i;
        }

        return maxlen;
        
    
    }
};