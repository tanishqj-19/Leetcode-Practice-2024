class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();


        int maxi = INT_MIN, mine = arrays[0][0], maxe = arrays[0].back();

        for(int i = 1; i<n; i++){
            maxi =  max(maxi, max(abs(maxe - arrays[i][0]), 
                    abs(arrays[i].back() - mine)));
            maxe = max(maxe, arrays[i].back()),
            mine = min(mine, arrays[i][0]);

        
        }

        return maxi;


    }
};