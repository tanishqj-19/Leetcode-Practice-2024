class Solution {
public:
    int balancedString(string s) {
        

        unordered_map<char, int> freq;

        for(auto& c: s) freq[c]++;
        int n = s.size(), l = 0, r = 0;
        int  minlen = n;
        for(;r < n; r++){
            freq[s[r]]--;

            while(l < n && freq['Q'] <= n/4 && freq['W'] <= n/4 && freq['R'] <= n/4 && freq['E'] <= n/4){
                minlen = min(minlen, r - l + 1);
                freq[s[l]]++;
                l++;
            }



        }
        return minlen;
    }
};