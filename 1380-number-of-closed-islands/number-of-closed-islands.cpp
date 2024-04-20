class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
    int dfs(int i, int j,vector<vector<int>>& grid,vector<vector<bool>> & vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()|| grid[i][j] == 1 || vis[i][j])
            return 0;
        
        vis[i][j] = true;
    
        for(int x = 0; x < 4; x++){
            dfs(i + dir[x], j + dir[x + 1], grid, vis);
        }
        
        return 1;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();
   
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(i == 0 || j == m-1 || j == 0 || i == n-1){
                    if(grid[i][j] == 0 && !vis[i][j] ){
                        dfs(i, j, grid, vis);
                    
                   
                    }
                }
            }
        }
        int islands = 0;
        for(int i=1; i<n-1; i++){
            for(int j =1; j<m-1; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    islands+= dfs(i, j, grid, vis);
                    
                   
                }
            }
        }

        return islands;
    }
};