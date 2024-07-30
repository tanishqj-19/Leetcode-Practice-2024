class Solution {
    int n;
public:
    int minimumDeletions(string s) {
        n = s.size();

        vector<int> prefix(n, 0), suffix(n, 0);
        int b = 0, a = 0;
        for(int i = 0; i<n; i++){
            prefix[i] = b;
            b += (s[i] == 'b');
            
        }

        for(int i = n-1; i>=0; i--){
            suffix[i] = a;
            a += (s[i] == 'a');
        }
        int cnt = n;
        for(int i = 0; i<n; i++){
            cnt = min(cnt, prefix[i] + suffix[i]);
        }


        return cnt;
        
    }
};