class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int l =INT_MAX, r = 0;
        for(auto &x: intervals){
            l = min(l, x[0]);
            r = max(r, x[1]);
        }

        vector<int> lineSweep(r + 2, 0);

        for(auto &x: intervals){
            lineSweep[x[0]]++;
            lineSweep[x[1] + 1]--;
        }

        int minGroups = 0, currGroup = 0;

        for(int i = l; i <= r + 1; i++){
            currGroup += lineSweep[i];
            minGroups = max(minGroups, currGroup);
        }
        return minGroups;
    }
};