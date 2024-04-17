class Solution {
    vector<int> ans;

    bool dfs(int node, vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &pathVis ){
        vis[node] = true;
        pathVis[node] = true;


        for(int nei: graph[node]){
            if(!vis[nei]){
                if(dfs(nei, graph, vis, pathVis))
                    return true;
            }else if(pathVis[nei]){
                return true;
            }
        }




        pathVis[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        

        
        int n = graph.size();
        
        
        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis);
                    
                
            }
        }

        for(int i=0; i<n; i++){
            if(pathVis[i] == false && vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};