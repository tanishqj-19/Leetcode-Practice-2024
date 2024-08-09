class Solution {
    bool isMagic(vector<vector<int>>& grid, int &row, int &col){
        bool vis[10] = {false};

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int value = grid[row + i][col + j];
                if(value < 1 || value > 9 || vis[value])
                    return false;
                vis[value] = true;
            }
        }
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        for(int i = 0; i < 3; i++){
            if(grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum)
                return false;
            if(grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum)
                return false;
        }

        if(grid[row][col] + grid[row  + 1][col + 1] + grid[row + 2][col + 2] != sum)
            return false;
        if(grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum)
            return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n < 3 || m < 3)
            return 0;
        int cnt = 0;
        for(int i = 0; i<=n-3; i++){
            for(int j = 0; j<=m-3; j++){
                
                if(isMagic(grid, i, j))
                    cnt++;
                
            }
        }


        return cnt;


    }
};