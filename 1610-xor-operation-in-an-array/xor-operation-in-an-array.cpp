class Solution {
public:
    int xorOperation(int n, int start) {
        int zor = 0;

        int i = 0;

        while(i < n){
            zor ^= start;
            start += 2;
            i++;
        }

        return zor;
    }
};