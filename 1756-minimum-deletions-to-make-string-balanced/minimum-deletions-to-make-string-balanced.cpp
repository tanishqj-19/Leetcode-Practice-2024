class Solution {
    int n;
public:
    int minimumDeletions(string s) {
        n = s.size();

        
        int b = 0, a = 0;
        for(int i = 0; i<n; i++){
            b += (s[i] == 'b');
            
        }
        int cnt = n;
        for(int i = n-1; i>=0; i--){
            b -= (s[i] == 'b');
            cnt = min(cnt, a + b);
            a += (s[i] == 'a');
            
        }
        
   
        return cnt;
        
    }
};