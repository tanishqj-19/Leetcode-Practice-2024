class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(int i, int j,vector<vector<int>>& grid,int &n, int &m, vector<vector<bool>> & vis){
        if(i >= n || j >= m || i < 0 || j < 0 || !grid[i][j] || vis[i][j])
            return;
        vis[i][j] = true;
        
        
        
        for(int k = 0; k<4; k++){
            int ni = dir[k] + i, nj = dir[k + 1] + j;

            dfs(ni, nj, grid, n, m, vis);
        }
    }

    int lands(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int island = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] && !vis[i][j]){
                    dfs(i, j, grid, n, m, vis);
                    island++;
                }
            }
        }

        return island;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        int  n = grid.size(), m = grid[0].size();
        int island = lands(grid);

        if(island != 1)
            return 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                        
                    grid[i][j] = 0;

                    island = lands(grid);
                    if(island != 1)
                        return 1;

                    grid[i][j] = 1;
                    
                }
            }
        }

        return 2;
        
    }
};