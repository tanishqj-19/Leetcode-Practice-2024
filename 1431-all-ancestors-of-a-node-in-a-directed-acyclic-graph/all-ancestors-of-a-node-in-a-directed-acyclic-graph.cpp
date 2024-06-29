class Solution {

    vector<bool> vis;
    void dfs(int node, vector<vector<int>> &adj, vector<set<int>> &ancest){
        if(vis[node])
            return;
        vis[node] = true;

        for(auto &nei: adj[node]){
           
            if(!vis[nei])
                dfs(nei, adj, ancest);
            if(ancest[nei].empty() == false){
                for(int i: ancest[nei])
                    ancest[node].insert(i);

            }
            ancest[node].insert(nei);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<set<int>> ancest(n);
        for(auto &e: edges){
            adj[e[1]].push_back(e[0]);
        }
        vis.resize(n, false);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, ancest);
            }
        }

        vector<vector<int>> res(n);
        for(int i = 0; i<n; i++){
            if(!ancest[i].empty()){
                for(auto &x: ancest[i])
                    res[i].push_back(x);
            }
        }

        return res;
    }
};