class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j = 0;
        int count[3] = {0}, total = 0;
        for(; j< n; j++){
            count[s[j] - 'a']++;

            while(count[0] >= 1 && count[1] >= 1 && count[2] >= 1){
                total += (n-j);
                count[s[i] - 'a']--;
                i++;
            }


        }

        return total;
    }
};