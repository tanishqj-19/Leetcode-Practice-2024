class Solution {
public:
    int maximumSwap(int num) {
        string s  = to_string(num);

        int  n  = s.size();
        int idx1 = -1, idx2 = -1, maxRight = -1;

        for(int i = n-1; i>=0; i--){

            if(maxRight == -1 || s[i] > s[maxRight]){
                maxRight = i;
            }else if(s[i] < s[maxRight]){
                idx1 = i;
                idx2 = maxRight;
            }
        }

        if(idx1 != -1 && idx2 != -1){
            swap(s[idx1], s[idx2]);
        }

        return stoi(s);
    }
};