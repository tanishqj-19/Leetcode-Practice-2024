class Solution {
public:
    bool judgeSquareSum(int c) {
        
        unordered_map<long long, bool> mp;

        for(int  i = 0; i<=sqrt(c); i++){
            mp[pow(i, 2)] = true;
        }


        for(int i = 0; i<=sqrt(c); i++){
            if(mp.find(c - pow(i, 2)) != mp.end())
                return true;
        }

        return false;
    }
};