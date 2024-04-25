class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n  =mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));


        for(int i=0; i<n; i++){
            prefix[i][0] = mat[i][0];
            for(int j = 1; j<m; j++){
                prefix[i][j] = prefix[i][j-1] + mat[i][j];
            }
        }

        for(int c = 0; c < m; c++){
            prefix[0][c] = prefix[0][c];
            for(int r = 1; r < n; r++){
                prefix[r][c] = prefix[r-1][c] + prefix[r][c];
            }
        }

        for(int i=0; i<n; i++){
            int ru = max(i-k, 0);
            int rd = min(i + k, n-1);

            for(int j=0; j<m; j++){
                int cl = max(0, j-k), cr = min(m-1, j + k);
                int value = prefix[rd][cr];
                if(ru - 1 >= 0){
                    value -= prefix[ru-1][cr];
                }

                if(cl - 1 >= 0){
                    value -= prefix[rd][cl-1];
                }

                if(ru-1 >= 0 && cl-1 >= 0)
                    value += prefix[ru-1][cl-1];

                mat[i][j] = value;
            }
        }

        return mat;


    }
};