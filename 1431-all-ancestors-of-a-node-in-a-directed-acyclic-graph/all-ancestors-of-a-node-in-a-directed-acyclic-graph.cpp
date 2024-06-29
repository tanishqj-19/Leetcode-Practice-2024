class Solution {

    
    void dfs(int node, int ancestor, vector<vector<int>> &adj, vector<vector<int>> &ancest){
        

        for(auto &nei: adj[node]){
           
            if(ancest[nei].empty() || ancest[nei].back() != ancestor){
                ancest[nei].push_back(ancestor);
                dfs(nei, ancestor, adj, ancest);
            }
            
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ancest(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
        }

        for(int i = 0; i<n; i++){
            dfs(i, i, adj, ancest);
        }

        

        return ancest;
    }
};