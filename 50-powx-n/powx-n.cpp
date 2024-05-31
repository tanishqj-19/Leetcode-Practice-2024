class Solution {
public:
    double myPow(double x, int n) {
        double sol = 1;
        long long temp = abs(n);

        bool neg = false;
        if(n < 0) neg = true;

        while(temp){
            if(temp % 2 == 0){
                x *= x;
                temp /= 2;
            }else {
                sol *= x;
                temp--;
            }
        }

        if(neg){
            return (1.0) / (sol);
        }
        return sol;


    }
};