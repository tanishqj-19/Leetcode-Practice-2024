class Solution {
public:
    int minBitFlips(int start, int goal) {
        int minFlips = 0;
        int i = 0;

        while(start != goal){
            if((start & (1 << i)) != ( goal & (1 << i))){
                minFlips++;
                start = (start ^ (1 << i));

            }
            i++;
        }

        return minFlips;
    }
};