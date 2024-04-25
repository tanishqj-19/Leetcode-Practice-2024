class Solution {
public:
    int maxSum(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();
        if(n < 3 || m < 3)
            return -1;
            
        int maxsum = 0;
        for(int i=1; i<n-1; i++){
        
            for(int j = 1; j<m-1; j++){
                int sum = mat[i][j] + mat[i-1][j] + mat[i + 1][j] + mat[i-1][j-1] + mat[i-1][j+1]
                        + mat[i + 1][j+1] + mat[i + 1][j-1];
                maxsum = max(maxsum, sum);
            }
        }
        
        
        return maxsum;
    }
};