class Solution {
public:
    bool judgeSquareSum(int c) {
        
        unordered_set<long long> mp;

        for(int  i = 0; i<=sqrt(c); i++){
            long long x = pow(i, 2);
            mp.insert(x);

            if(mp.count(c - x) > 0)
                return true;

        }



        return false;
    }
};