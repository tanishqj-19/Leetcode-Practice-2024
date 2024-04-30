class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dir = {0, 1, 0, -1, 0};
        int n = heights.size(), m = heights[0].size();


        int minH = abs(heights[0][0] - heights[n-1][m-1]);

        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>  > pq;

        pq.push({0, {0,0}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;


        while(!pq.empty()){
            int d = pq.top().first;
            int i = pq.top().second.first, j = pq.top().second.second; pq.pop();

            if(i == n-1 && j == m - 1){
                return d;
            }

            for(int x = 0; x < 4; x++){
                int nx = dir[x] + i , ny = dir[x + 1] + j;

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                
                int newDiff = max(abs(heights[i][j] - heights[nx][ny]), d);
                
                if(newDiff < dis[nx][ny]){
                    dis[nx][ny] = newDiff;
                    pq.push({newDiff, {nx, ny}});
                }
                
            }
        }



        return -1;



    }
};