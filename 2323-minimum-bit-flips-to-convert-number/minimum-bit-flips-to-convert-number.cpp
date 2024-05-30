class Solution {
public:
    int minBitFlips(int start, int goal) {
        int minFlips = 0;
        int i = 0;

        start ^= goal;

        for(int i = 0; i<32; i++){
            if(start & (1 << i))
                minFlips++;
        }

        return minFlips;
    }
};