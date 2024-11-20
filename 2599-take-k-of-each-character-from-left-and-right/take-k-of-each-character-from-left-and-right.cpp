class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> freq(3, 0);

        for(char &c : s) freq[c - 'a']++;

        if(freq[0] < k || freq[1] < k || freq[2] < k)
            return -1;
        int i = 0, j = 0;
        vector<int> curr(3, 0);
        int minCount = 0;
        while(j < n){
            curr[s[j] - 'a']++;

            while(i <= j && (freq[0] - curr[0] < k || freq[1] - curr[1] < k || freq[2] - curr[2] < k)){
                curr[s[i] - 'a']--;
                
                i++;
            }

            
            minCount = max(minCount, j - i + 1);
            

            j++;

        }

        return n - minCount;
    }
};