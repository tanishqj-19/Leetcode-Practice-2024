class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int l =1, r = 1e6 + 2;
        

        vector<int> lineSweep(r, 0);

        for(auto &x: intervals){
            lineSweep[x[0]]++;
            lineSweep[x[1] + 1]--;
        }

        int minGroups = 0, currGroup = 0;

        for(int i = l; i < r; i++){
            currGroup += lineSweep[i];
            minGroups = max(minGroups, currGroup);
        }
        return minGroups;
    }
};