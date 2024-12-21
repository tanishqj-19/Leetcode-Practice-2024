class Solution {
    vector<long long> dp;
    long long dfs(vector<vector<int>> &adj,  int &components, vector<bool> &vis, vector<int> &values, int node, int k) {
        vis[node] = true;

        for (auto &nei : adj[node]) {
            if (!vis[nei]) {
               dp[node] +=  dfs(adj,  components, vis, values, nei, k);
            }
        }

        if (dp[node] % k == 0) {
            components++;
            
        }

        return dp[node];
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        vector<vector<int>> adj(n);

    
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i = 0; i<n; i++) dp.push_back(values[i]);

        int components = 0;
        vector<bool> vis(n, false);
        dfs(adj,  components, vis, values, 0, k);
        

        return components;
    }
};
