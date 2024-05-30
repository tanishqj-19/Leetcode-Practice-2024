class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;

        int sign = 1;

        
        if(dividend < 0 && divisor < 0)
            sign = 1;
        else if(dividend < 0 || divisor < 0)
            sign = -1;
        
        unsigned int x = abs(dividend);
        unsigned int y = abs(divisor);  
        unsigned int q  = 0;

        while(x >= y){
            int i = 0;

            while(x > (y << (i + 1)) ) i++;
            
            q = q + (1 << i);
            x = x - (y << i);
        }



    
        if(q == (1<<31) && sign == 1)
            return INT_MAX;
        
        return sign == 1 ? q: -q;


    }
};