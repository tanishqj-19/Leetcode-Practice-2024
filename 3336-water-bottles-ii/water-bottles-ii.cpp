class Solution {
public:
    int maxBottlesDrunk(int n, int exchange) {
        int res = n ;

        while(n){
            n -= exchange;
            
            if(n < 0)
                break;
            n++;
            res++;
            exchange++;
            
        }

        return res;
    }
};