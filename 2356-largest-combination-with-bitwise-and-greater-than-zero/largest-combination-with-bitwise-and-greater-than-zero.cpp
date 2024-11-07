class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(), maxCount = 0;

        for(int i = 0; i<32; i++){
            int cnt = 0;

            for(int &x: candidates){
                if((x & (1 << i)) != 0){
                    cnt++;
                }
            }
            maxCount = max(maxCount, cnt);
        }


        return maxCount;

    }
};