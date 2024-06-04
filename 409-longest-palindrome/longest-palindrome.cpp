class Solution {
public:
    int longestPalindrome(string s) {
        int maxlen = 0;

        vector<int> count(213, 0);

        for(auto &c: s) count[c]++;

       
        int odd = 0;
        for(int i = 0; i<213; i++){
            if(count[i] % 2 == 0){
                maxlen += count[i];
            }else{
                maxlen += (count[i] - 1);
                odd = 1;
            }
        }
        

        return maxlen + odd;
    }
};