class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles != 0){
            
            
            int x = numBottles / numExchange, carry = numBottles % numExchange;
            ans += x;
            if(x == 0)
                break;
            numBottles = x + carry;

        }

        return ans;
    }
};