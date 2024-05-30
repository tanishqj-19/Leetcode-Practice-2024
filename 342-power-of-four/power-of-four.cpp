class Solution {
public:
    bool isPowerOfFour(int n) {
        int bit = 0, i = 1, pos = 0;
        if(n < 0)
            return false;

        while(n){
            if(n & 1){
                bit++;
                pos = i;
            }
            i++;
            n >>= 1;
        }

        return bit == 1 && pos & 1;

    }
};