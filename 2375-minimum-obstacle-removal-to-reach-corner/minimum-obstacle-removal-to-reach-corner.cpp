class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        
        pq.push({0 + grid[0][0], {0, 0}});
        
        int minCost = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<int> dir = {0, -1, 0, 1, 0};
        while(!pq.empty()){
            int cost = pq.top().first;
            auto [r, c] = pq.top().second; pq.pop();

            if(r == n-1 && c == m-1){
                return cost + grid[r][c];
            }
            for(int i = 0; i<4; i++){
                int nr = r + dir[i], nc = c + dir[i + 1];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc])
                    continue;
                vis[nr][nc] = true;
                
                pq.push({cost + grid[nr][nc], {nr, nc}});
            }

        }

        return -1;
    }
};