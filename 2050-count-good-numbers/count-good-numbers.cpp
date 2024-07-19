class Solution {

    const long long mod = 1e9 + 7;
    long long power(long long  y, long long n){
        long long sol = 1;
        long long x = y;
        while(n){
            if(n % 2 == 0){
                x  = (x * x) % mod;
                n >>= 1;
            }else {
                sol  = (sol * x) % mod;
                n--;
            }

        }
        return sol ;

    }
public:
    int countGoodNumbers(long long n) {
        if(n % 2 == 0){
            long long even = power(5, n/2) % mod;
            long long odd = power(4, n/2) % mod;

            return (even * odd) % mod;
        }else{
            long long even = power(5, n/2 + 1) % mod;
            long long odd = power(4, n/2) % mod;

            return (even * odd) % mod;
            
        }
        // return ;
    }
};