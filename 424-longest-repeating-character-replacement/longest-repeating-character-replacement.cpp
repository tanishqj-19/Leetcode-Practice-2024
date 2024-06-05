class Solution {
public:
    int characterReplacement(string s, int k) {
        int  i = 0, j = 0, n =s.size();


        int maxFreq = 0, maxlen = 0;
        int freq[26] = {0};
        for(; j < n; j++){
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            while(j - i + 1 - maxFreq > k){
                freq[s[i] - 'A']--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};