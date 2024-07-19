class Solution {

    int mod = 1e9 + 7;


    long long power(long long x, long long n){
        long long sol = 1;

        x = x % mod;
        if(x == 0) return 0;


        while(n > 0){
            if(n & 1){
                sol  = (sol * x) % mod;
            }
            n = n >> 1;
            x  = (x * x) % mod;
            

        }

        return sol;
        
    }
public:
    int countGoodNumbers(long long n) {
        long long n4 = n/2;
        long long n5 = n - n4;
        long long ans =((power(4LL, n4) % mod * power(5LL, n5) % mod) % mod);
        return (int) ans % mod;
    }
};