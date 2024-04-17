class Solution {
    stack<int> st;
    bool dfs(int node, vector<int> adj[], vector<int>&vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei]){
                if(dfs(nei, adj, vis, pathVis))
                    return true;
            }else if(pathVis[nei]){
                return true;
            }
        }
        
        st.push(node);
        pathVis[node] = 0;
        
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis))
                    return {};
            }
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        
        return ans;
    }
};