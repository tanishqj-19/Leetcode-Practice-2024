class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0)
            return true;
        auto rev = [](int n) {
            int rn = 0;
            for (; n; n /= 10)
                rn = rn * 10 + n % 10;
            return rn;
        };  
        
        for(int i = num/2; i<=num; i++){
            
            if(rev(i) + i == num)
                return true;
        }

        return false;
    }
};