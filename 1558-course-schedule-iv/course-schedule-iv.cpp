class Solution {

    bool dfs(int node, int target, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        if(node == target)
            return true;
        for(int nei: adj[node]){
            if(!vis[nei]){
                if(dfs(nei, target, adj, vis))
                    return true;
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];

        for(vector<int>& i:pre){
            adj[i[0]].push_back(i[1]);
        }

        vector<bool> ans;
        for(vector<int> &q: queries){
            int u = q[0], v = q[1];
            vector<bool> vis(n, false);
            bool x = dfs(u, v, adj, vis);
            ans.push_back(x);

        }

        return ans;
    }
};