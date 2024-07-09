class Solution {
     vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(int i, int j, vector<vector<int>> &board, vector<vector<bool>> &vis, int n, int m){
        if(i < 0 || i >= n || j < 0 || j>=m|| vis[i][j] || board[i][j] == 0){
            return;
        }

        vis[i][j] = true;

        for(int k=0; k<4; k++){
            dfs(i + dir[k] , j + dir[k + 1], board, vis, n, m);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, grid, vis, n, m);
            }

            if(!vis[i][m-1] && grid[i][m-1] == 1)
                dfs(i, m-1, grid, vis,n, m);
        }
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0, i, grid, vis, n, m);
            }

            if(!vis[n-1][i] && grid[n-1][i] == 1)
                dfs(n-1, i,grid, vis,n, m);
        }

        int c= 0 ;

        for(int i  = 0 ;i<n; i++){
            for(int j = 0; j<m;j++){
                if(!vis[i][j] && grid[i][j])
                    c++;
            }
        }
        return c;

        
    }
};