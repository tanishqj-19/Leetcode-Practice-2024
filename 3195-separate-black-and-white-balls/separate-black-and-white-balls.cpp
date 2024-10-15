class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        int zero = 0;
        for(int i=n-1; i>= 0; i--){
            if(s[i] == '0'){
                zero++;
            }
            if(s[i] == '1'){
                ans += zero;
            }
        }
        
        return ans;
    }
};