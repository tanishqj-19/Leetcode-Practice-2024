
class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int fresh = 0;
        for(int i = 0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] =true;
                    q.push({0, i, j});
                }else if(grid[i][j] == 1)
                    fresh++;
            }
        }


    
        int minTime = 0;
        while(!q.empty()){
            int t = q.front()[0],  r = q.front()[1], c = q.front()[2];
            q.pop();
            minTime = max(t, minTime);

            for(int k = 0; k<4; k++){
                int  i = r + dir[k], j = c + dir[k + 1];

                if(i < 0 || j < 0 || j >= m || i >= n || grid[i][j] != 1 || vis[i][j])
                    continue;
                fresh--;
                vis[i][j] = true;
                q.push({t + 1, i, j});
            }
        }

        
        return fresh == 0 ? minTime: -1;
    }
};
