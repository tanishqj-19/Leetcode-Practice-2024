class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mat[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= mat[i][j], colSum[j] -= mat[i][j];
            }
        }

        return mat;

    }
};