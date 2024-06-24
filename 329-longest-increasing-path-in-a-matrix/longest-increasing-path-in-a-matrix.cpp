class Solution {
    int n, m;
    int maxC = 0;
        vector<int> dir = {0,1,0,-1, 0};

    int  dfs(int i, int j , vector<vector<int>>& matrix, vector<vector<int>> &vis){
        if(vis[i][j])
            return vis[i][j];

   

        for(int k = 0; k<4; k++){
            int nx = i + dir[k], ny = j + dir[k + 1];
            if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;

            if(matrix[nx][ny] >= matrix[i][j]) continue;


            vis[i][j]  = max(vis[i][j], dfs(nx, ny, matrix, vis));


        }


        return ++vis[i][j];


        

        }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i<n; i++){
            for(int  j = 0; j<m; j++){

                maxC = max(maxC, dfs(i, j, matrix, vis));
            }
        }
        return maxC;        
    }
};