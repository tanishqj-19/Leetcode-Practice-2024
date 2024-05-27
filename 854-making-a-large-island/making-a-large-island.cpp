class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        for(int i = 0; i<n; i++){
           parent.push_back(i);
           size.push_back(1); 
        }
    }


    int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionRank(int u, int v){
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

};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();


        DisjointSet ds(n * n);

        vector<int> dir = {0, -1, 0, 1, 0};
        // Union connection between connected 1's

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k<4; k++){
                        int r = i + dir[k], c = j + dir[k + 1];

                        if(r >= n ||  c>= n || r<0 || c < 0 || 
                        grid[r][c] == 0) continue;
                        int node1 = (r * n + c ), node2 = (i * n + j);
                        ds.unionRank(node1, node2);
                    }
                }
            }
        }

       

        int maxLand = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){

                if(grid[i][j] == 0){
                    int currMax = 0;
                    unordered_set<int> st;
                    for(int k = 0; k<4; k++){
                        int nr = i + dir[k], nc = j + dir[k + 1];

                        if(nr < 0 || nc < 0 || nr >= n || nc >= n 
                            || grid[nr][nc] == 0) continue;
                        int x = nr * n + nc;
                        st.insert(ds.find(x));
                        
                    }

                    for(auto &it: st){
                        
                        currMax += ds.size[it];
                    }
                    currMax++;
                    maxLand = max(currMax, maxLand);
                }
            }
        }

        if(maxLand == 0)
            return n * n;


        return maxLand;



    }
};