class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> luckies;
        vector<int> row(n, 1e6), col(m, 0);
        for(int i = 0; i <n ; i++){
            for(int j = 0; j<m; j++){
                row[i] = min(row[i], matrix[i][j]);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                col[i] = max(col[i], matrix[j][i]);
            }
        }

        for(int i = 0; i <n ; i++){
            for(int j = 0; j<m; j++){
                if(row[i] == col[j])
                    luckies.push_back(row[i]);
            }
        }

        

        return luckies;
    }
};