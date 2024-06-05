class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(),  j = 0;
        int total = 0;
        vector<int> last(3, -1);
        for(; j< n; j++){
            last[s[j] - 'a'] = j;

            total += (min(last[0], min(last[1], last[2])) + 1);


        }

        return total;
    }
};