class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n  =mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));


        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                

                for(int r = i - k; r <= i + k; r++){
                    for(int c = j - k; c <= j + k; c++){
                        if(r >= 0 && r < n && c >= 0 && c < m){
                            res[i][j] += mat[r][c];
                        }
                    }
                }
            }
        }

        return res;


    }
};