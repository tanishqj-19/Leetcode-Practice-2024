class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int len = 0;
        for(int i = 0; i<n; i++){
            int cost = 0, c= 0;
            for(int j = i; j<n; j++){
                cost += abs(s[j] - t[j]);
                if(cost > maxCost)
                    break;
                c++;
                
            }

            len = max(len, c);
        }

        return len;
    }
};