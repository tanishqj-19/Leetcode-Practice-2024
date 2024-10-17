class Solution {
public:
    int maximumSwap(int num) {
        string s  = to_string(num);

        int n  = s.size();
        
        for(int i = 0; i<n; i++){
            string temp = s;
            for(int j = i + 1; j<n; j++){
                swap(temp[i], temp[j]);

                num = max(num, stoi(temp));
                swap(temp[i], temp[j]);

            }
        }

        return num;
    }
};