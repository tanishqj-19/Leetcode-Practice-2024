class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        
        vector<vector<int>> matrix(n, vector<int>(n, 1e4 + 1));
        for(auto &vec: edges){
            int u = vec[0], v = vec[1], w = vec[2];

            matrix[u][v] = matrix[v][u] = w;
            matrix[u][u] = matrix[v][v] = 0;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i <n; i++){
                for(int j = 0; j<n; j++){

                    
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    
                }
            }
        }

        int least = n, ans = -1;

        for(int  i =0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                // cout<<matrix[i][j]<<" ";
                if(matrix[i][j] <= dist)
                    c++;
            }
            
            // cout<<endl;
            if(c <= least){
                ans = i;
                least = c;
            }
        }

        return ans;
    }
};