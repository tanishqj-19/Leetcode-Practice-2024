class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        int zor = 0;
        vector<int> cnt(51, 0);

        for(int &i: nums) cnt[i]++;


        for(int i = 1; i<=50; i++){
            if(cnt[i] == 2){
                zor ^= i;
            }
        }

        return zor;
    }
};