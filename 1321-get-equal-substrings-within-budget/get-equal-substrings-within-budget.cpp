class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int len = 0, cost = 0, c = 0, j = 0;
        for(int i = 0; i<n; i++){
            
            int d = abs(s[i] - t[i]);

            cost += d;
            c++;

            while(j < n && cost > maxCost){
                cost -= abs(s[j] - t[j]);
                j++;
                c--;
            }
          

            len = max(len, c);
        }

        return len;
    }
};