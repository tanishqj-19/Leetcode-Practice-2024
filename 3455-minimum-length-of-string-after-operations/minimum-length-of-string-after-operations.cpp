class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        int len = s.size();
        for(char &x: s){
            freq[x]++;

            if(freq[x] > 2){
                len -= 2;
                freq[x] = 1;
            }
        }

        return len;
    }
};