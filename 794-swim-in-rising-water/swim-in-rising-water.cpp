class DisjointSet{
public:
    vector<int> parent, size, rank;

    DisjointSet(int n){
        for(int i = 0; i<n; i++){
           parent.push_back(i);
           size.push_back(1); 
           rank.push_back(0);
        }
    }


    int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionSize(int u, int v){
        int ulu = find(u), ulv = find(v);

        if(ulu == ulv)
            return;
        if(size[ulu] >= size[ulv]){
            parent[ulv] = ulu;
            size[ulu] += size[ulv];
        }
        else{
            parent[ulu] = ulv;
            size[ulv] += size[ulu];

        }

        return;
    }
    void unionRank(int x, int y){
        int upx = find(x), upy = find(y);

        if(upx == upy){
            
            return;
        }
        if(rank[upx] > rank[upy]){
            parent[upy] = upx;
        }else if(rank[upx] < rank[upy]){
            parent[upx] = upy;
        }else{
            parent[upx] = upy;
            rank[upx]++;
        }
    }

};

bool isValid(int i, int j , int n){
    return i >= 0 && i < n && j >= 0 && j < n;
}

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n *n);

        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
        int ans = 0;
        pq.push({grid[0][0], {0,0}});
        bool vis[n][n];
        memset(vis, false, sizeof vis);
        vis[0][0] = true;
        vector<int> dir = {0, -1, 0, 1, 0};
        while(!pq.empty()){
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            ans = max(ans, d);
            pq.pop();
            int mini = INT_MAX, minR = -1, minC = -1;
            
            if(i == n-1 && j == n-1){
                return ans;
            }

            for(int k = 0; k<4; k++){
                int r = i + dir[k], c = j + dir[k + 1];
                if(isValid(r, c, n) && !vis[r][c]){
                    pq.push({grid[r][c], {r, c}});
                    vis[r][c] = true;
                   
                }
            }
            

            
        }

    return -1;


    }

};