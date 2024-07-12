#define piii pair<int, pair<int, int>>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        queue<piii> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 0;

         vector<vector<int>> dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

        grid[0][0] = 1;

        while(pq.empty() == false){
            int d = pq.front().first, i = pq.front().second.first, j = pq.front().second.second;
            pq.pop();

            if(i == n-1 && j == n-1)
                return d + 1;

            for(auto &k: dir){
                int nr = i + k[0], nc = j + k[1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && d + 1 <dis[nr][nc] ){
                    pq.push({d + 1, {nr, nc}});
                    grid[nr][nc] = 1;
                }
                    
            }




        }
        return -1;
    }
};