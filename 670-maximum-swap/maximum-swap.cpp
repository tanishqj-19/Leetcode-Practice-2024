class Solution {
public:
    int maximumSwap(int num) {
        string s  = to_string(num);

        int n  = s.size();
        
        for(int i = 0; i<n; i++){
            
            for(int j = i + 1; j<n; j++){
                swap(s[i], s[j]);

                num = max(num, stoi(s));
                swap(s[i], s[j]);

            }
        }

        return num;
    }
};