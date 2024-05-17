class Solution {
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionGraph(int u, int v){
        int upu = find(u), upv = find(v);

        if(rank[upu] < rank[upv]){
            parent[upu] = upv;
        }else if(rank[upv] < rank[upu]){
            parent[upv] = upu;
        }else{
            parent[upu] = upv;
            rank[upv]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();

        if(m < n-1)
            return -1;
        
        rank.resize(n, 0);
        parent.resize(n);
        for(int  i = 0; i<n; i++) parent[i] = i;

        for(vector<int> &c: con){
            unionGraph(c[0], c[1]);
        }
        int ans = 0;

        for(int  i = 0; i<n; i++){
            if(find(i) != find(0)){
                unionGraph(i, 0);
                ans++;
            }
        }

        return ans;

        
    
        


        
    }
};