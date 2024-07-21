class Solution {
public:
    int minChanges(int n, int k) {
        k ^= n;
        int ones = __builtin_popcount(k);

        k &= n;
        int c = __builtin_popcount(k);


        return ones == c ? ones : -1;

       

    }
};