class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        pq.push({0, {0, 0}});
        
        int minCost = 0;
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<int> dir = {0, -1, 0, 1, 0};
        while(!pq.empty()){
            int cost = pq.top().first;
            auto [r, c] = pq.top().second; pq.pop();

            if(r == n-1 && c == m-1){
                return cost;
            }
            if(vis[r][c])
                continue;
            vis[r][c] = true;
            for(int i = 0; i<4; i++){
                int nr = r + dir[i], nc = c + dir[i + 1];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc])
                    continue;
                int waiting = 0;
                if( grid[nr][nc] > cost  +  1){
                    int diff = grid[nr][nc] - cost - 1;
                    waiting = (diff % 2 == 0) ? diff : diff + 1;

                }
                pq.push({cost + 1 + waiting , {nr, nc}});

            }

        }

        return -1;
        

    
    }
};