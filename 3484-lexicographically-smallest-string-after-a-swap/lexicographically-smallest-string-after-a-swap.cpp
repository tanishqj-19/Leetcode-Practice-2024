class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        int one = 0;
        for(int i = 1; i<n; i++){

            if(s[i-1] - '0' <= s[i] - '0')
                continue;

            if(one == 0){
                if((s[i] - '0') % 2 == 0 && (s[i-1] - '0') % 2 == 0){
                    one++;
                    swap(s[i], s[i-1]);
                }else if((s[i] - '0') % 2 != 0 && (s[i-1] - '0') % 2 != 0){
                    swap(s[i], s[i-1]);
                    one++;
                }
            }
        }

        return s;
    }
};