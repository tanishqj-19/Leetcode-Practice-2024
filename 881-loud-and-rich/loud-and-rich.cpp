class Solution {
    unordered_map<int, vector<int>> adj;
    int dfs(int node,  vector<int> &quiet, vector<int> &ans){
        if(ans[node] >= 0)
            return ans[node];
        ans[node] = node;

        for(int nei: adj[node]){
            int x = dfs(nei,  quiet, ans);
            
            if(quiet[ans[node]] > quiet[x]){
                ans[node] = ans[nei];
            }
        }

        return ans[node];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        

        for(vector<int> &rich: richer){
            adj[rich[1]].push_back(rich[0]);
        }

        vector<int> ans(quiet.size(), -1);
        for(int i=0; i<quiet.size();i++){
            dfs(i, quiet, ans);
        }

        return ans;
    }
};