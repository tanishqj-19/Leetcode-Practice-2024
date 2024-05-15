class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dis){

        int n = grid.size();

        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            for(int  j = 0; j<n; j++){
                if(grid[i][j]){
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            int s = dis[i][j];
            for(int k = 0; k<4; k++){
                int x = dir[k] + i, y = dir[k + 1] + j;

                if(x >= 0 && x < n && y >= 0 && y < n && dis[x][y] > 1 + s){
                    dis[x][y] = 1 + s;
                    q.push({x, y});
                }
            }
        }


        return;

    }
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int  n = grid.size();

        

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        bfs(grid, dis);

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<vector<int>> pq;

        pq.push({dis[0][0], 0, 0});

        while(!pq.empty()){
            int sc = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();

            if(i == n-1 && j == n-1){
                return sc;
            }
            vis[i][j] = true;

            for(int k = 0; k<4; k++){
                int x = dir[k] + i, y = dir[k + 1] + j;

                if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]){
                    vis[x][y] = true;
                    int  safe = min(dis[x][y], sc);
                    pq.push({safe, x, y});
                }
            }
        }





        return -1;

        
        


        







    }
};