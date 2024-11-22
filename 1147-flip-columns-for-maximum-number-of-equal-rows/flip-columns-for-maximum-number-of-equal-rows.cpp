class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxRows = 0;
        unordered_map<string, int> mp;
        for(vector<int> &row: matrix){
            string curr = "";
            for(int &colVal: row){
                curr += (colVal == row[0] ? 'T' : 'F');
            }
            mp[curr]++;
        }

        for(auto &x: mp) maxRows = max(maxRows, x.second);
        return maxRows;
    }
};