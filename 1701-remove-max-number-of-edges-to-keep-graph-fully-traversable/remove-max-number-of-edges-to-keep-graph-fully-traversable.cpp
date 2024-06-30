class DisjointSet{
    

    public:
    vector<int> parent;
    DisjointSet(int n){
        parent.resize(n);
        for(int i = 1; i<n; i++)parent[i]  = i;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    int unionSet(int u, int v){
        int up = find(u), vp = find(v);

        if(up == vp)
            return 0;
        parent[up] = vp;
        
        return 1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n+1);

        int remove = 0, eA = 0, eB = 0;
        for(auto &e: edges){
            if(e[0] == 3){
                if(ds.unionSet(e[1], e[2])){
                    eA++;
                    eB++;
                }else{
                    remove++;
                }
            }
        }
        vector<int> copy = ds.parent;
        for(auto &e: edges){
            if(e[0] == 2){
                if(ds.unionSet(e[1], e[2])){
                    eB++;
                }else{
                    remove++;
                }
            }
        }
        ds.parent = copy;
        for(auto &e: edges){
            if(e[0] == 1){
                if(ds.unionSet(e[1], e[2])){
                    eA++;
                }else{
                    remove++;
                }
            }
        }

        if(eA == n-1 && eB == n-1)
            return remove;
        return -1;
    }
};