class Solution {
    int oneCount(int k){
        int ones = 0;
        while(k){
            ones += (k & 1);
            k >>= 1;
        }

        return ones;
    }
public:
    int minChanges(int n, int k) {
        k ^= n;
        int ones = oneCount(k);

        k &= n;
        int c = oneCount(k);


        return ones == c ? ones : -1;

       

    }
};