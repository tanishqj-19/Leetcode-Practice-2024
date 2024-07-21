class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int maxops = 0, ones = 0;

        for(int i = 0; i<n; i ++){
            if(s[i] == '0'){
                maxops += ones;
                while(i < n && s[i] != '1')
                    i++;
            }
            ones++;
        }

        return maxops;
        
        
    }
};