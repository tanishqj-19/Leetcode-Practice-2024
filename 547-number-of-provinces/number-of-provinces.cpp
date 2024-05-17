class Solution {

    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    
    
public:
    int findCircleNum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        parent.resize(n + 1);
        

        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        int ans = n;
        

        
        for(int i = 0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                if(grid[i][j] == 1 ){
                    int u = find(i), v = find(j);

                    if(u != v){
                        parent[u] = v;
                        ans--;
                    }
                }
            }
        }


        
        return ans;
    }
};