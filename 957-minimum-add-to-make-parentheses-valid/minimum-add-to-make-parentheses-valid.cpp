class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        int bracket = 0;

        int ans = 0;
        for(char &c: s){
            if(c == '(')
                bracket++;
            else
                bracket--;
            if(bracket == -1){
                bracket++;
                ans++;
            }
        }

        ans += bracket;
        return ans;
    }
};