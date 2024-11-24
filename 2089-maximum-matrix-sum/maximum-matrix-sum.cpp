#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        ll maxSum = 0;
        int neg = 0, small = INT_MAX;
        for(int i = 0; i<n; i++){
            
            
            for(int j = 0; j<m; j++){
                maxSum += abs(matrix[i][j]);
                small = min(small, abs(matrix[i][j]));

                if(matrix[i][j] < 0) neg++;
            }

            
        }

        return neg % 2 == 0 ? maxSum : maxSum - 2 * small;
    }
};