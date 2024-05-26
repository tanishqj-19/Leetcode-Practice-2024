class DisjointSet{
public:
    vector<int> parent, rank;

    DisjointSet(int n){
        
        for(int i = 0; i<n+1; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int node){
        if(parent[node] == node)
            return node;
        return find(parent[node]);
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


class Solution {
    
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxR = 0, maxC = 0;
        for(auto &x: stones){
            maxR = max(maxR, x[0]);
            maxC = max(maxC, x[1]);

        }
        int sz = maxR + maxC + 1;
        
        DisjointSet ds(sz);

       
        unordered_map<int, int> nodes;
        for(auto &x: stones){

            int nodeR = x[0], nodeC = x[1] + 1 + maxR;
            ds.unionRank(nodeR, nodeC);
            nodes[nodeR] = nodes[nodeC] = 1;
        }

        int cnt = 0;
        for(auto &x: nodes){
            if(ds.find(x.first) == x.first)
                cnt++;
        }

        return n - cnt;

        



        
        
    }
};