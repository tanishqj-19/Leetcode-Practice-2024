class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<array<int, 3>> edges;
        for(int i = 0; i<n-1; i++){
            for(int j =  i + 1; j <n; j++){
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                edges.push_back({distance, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(n + 1);
        int minCost = 0, cnt = 0;
        for(auto &e: edges){
            int w = e[0], u = e[1], v = e[2];

            if(ds.find(u) == ds.find(v)) continue;
            cnt++;
            minCost += w;
            ds.unite(u, v);

            if(cnt == n-1)
                break;

        }

        return minCost;




        
    }
};