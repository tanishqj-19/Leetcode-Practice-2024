class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';

        int len = (1 << n);
        int count = 0;

        while(k > 1){

            if(k == len / 2){
                return count % 2 == 0 ? '1' : '0';
            }

            if(k > len / 2){
                k = len - k;
                count++;
            }
            len /= 2;
        }

        return count % 2 == 0 ? '0' : '1';
    }
};