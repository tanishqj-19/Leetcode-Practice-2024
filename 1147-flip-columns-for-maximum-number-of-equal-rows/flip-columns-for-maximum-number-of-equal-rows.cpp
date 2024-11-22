class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxRows = 0;

        for(int i = 0; i<n; i++){
            vector<int> flipped(m, 0);

            for(int j = 0; j<m; j++) flipped[j] = 1 - matrix[i][j];

            int identical = 0;

            for(auto &row : matrix){
                if(flipped ==  row || row == matrix[i])
                    identical++;
            }
            maxRows = max(maxRows, identical);
        }

        return maxRows;
    }
};