class Solution {
public:
    int longestPalindrome(string s) {
        int maxlen = 0;

        unordered_map<char, int> count;

        for(auto &c: s) count[c]++;

       
        int odd = 0;
        for(auto &x: count){
            if(x.second % 2 == 0)
                maxlen += x.second;
            else {
                odd = 1;
                maxlen += (x.second - 1);
            }
        }

        return maxlen + odd;
    }
};