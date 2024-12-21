class Solution {
    long long dfs(vector<vector<int>> &adj,  int &components, vector<bool> &vis, vector<int> &values, int node, int k) {
        vis[node] = true;
        long long sum = 0;
        for (auto &nei : adj[node]) {
            if (!vis[nei]) {
               sum +=  dfs(adj,  components, vis, values, nei, k);
            }
        }

        sum += values[node];
        if (sum % k == 0) {
            components++;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        vector<vector<int>> adj(n);

    
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }


        int components = 0;
        vector<bool> vis(n, false);
        dfs(adj,  components, vis, values, 0, k);
        

        return components;
    }
};
