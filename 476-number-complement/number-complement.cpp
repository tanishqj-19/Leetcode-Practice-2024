class Solution {
public:
    int findComplement(int num) {
        int  sum = 0,  i =0;

        while(sum < num){
            sum += (1 << i);
            i++;
        }

        return sum - num;
    }
};