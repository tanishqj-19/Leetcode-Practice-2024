class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long  low = 0, high = (long) sqrt(c);

        while(low <= high){
            long long mid = low * low + high * high;

            if(mid == c)
                return true;
            if(mid > c){
                high--;
            }else
                low++;
        }

        return false;
    }
};