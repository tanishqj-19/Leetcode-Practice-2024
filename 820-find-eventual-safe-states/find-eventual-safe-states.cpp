class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        queue<int> q;
        vector<int> in(n, 0);
        for(int i = 0; i<n; i++){
            if(!graph[i].empty()){
                for(auto &x: graph[i]){
                    adj[x].push_back(i);
                }
            }else{
                q.push(i);
            }
        }

        for(int i = 0; i<n; i++){
            for(auto &x: adj[i]){
                in[x]++;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();

            ans.push_back(node);

            for(auto &x: adj[node]){
                in[x]--;
                if(in[x] == 0)
                    q.push(x);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        


    }
};