class Solution {

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> & grid, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || vis[i][j]){
            return;
        }
        vis[i][j] = true;


        dfs(i+1, j, vis, grid, n, m);
        dfs(i-1, j, vis, grid, n, m);
        dfs(i, j +1, vis, grid, n, m);
        dfs(i, j-1, vis, grid, n, m);

        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int num = 0;

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    num++;
                    dfs(i, j, visited,grid,n,m);
                }
            }
        }


        return num;
    }
};