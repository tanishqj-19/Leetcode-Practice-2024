class Solution {

    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;

        for(auto n: adj[node]){
            if(!vis[n]){
                dfs(n, adj, vis);
            }
        }

        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1)
            return -1;
        vector<int> adj[n];

        for(auto &c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);

        }

        vector<bool> vis(n, false);
        int cables = -1;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cables++;
            }
        }

        return cables;
    }
};