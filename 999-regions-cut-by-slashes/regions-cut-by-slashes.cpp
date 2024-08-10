class Solution {
    void dfs(int &i, int &j, vector<vector<int>> &g){
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j])
            return;
        g[i][j] = 1;

        int dir[5] = {0, -1, 0, 1, 0}, ni, nj;
        for(int k = 0; k<4; k++){
            ni = i + dir[k], nj = dir[k + 1] + j;
            dfs(ni, nj, g);
        }
        return;
    }
    void buildGrid(vector<vector<int>> &grid, vector<string> &mat,int &n, int &m){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == '/'){
                    grid[i * 3][j * 3 + 2] = grid[i * 3 + 1][j * 3 + 1] = grid[i * 3 + 2][j * 3] = 1;
                }else if(mat[i][j] == '\\'){
                    grid[i * 3][j * 3] = grid[i * 3 + 1][j * 3 + 1] = grid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> grid(n * 3, vector<int>(m * 3, 0));

        buildGrid(grid, mat, n, m);

        n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};