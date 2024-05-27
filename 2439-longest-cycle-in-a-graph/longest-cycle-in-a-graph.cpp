class Solution {
    stack<int> st;
    void dfs(int node, vector<int> &edges, vector<bool> &vis){
        
        vis[node] = true;
        int child = edges[node];
        if(child != -1 && vis[child] == false){
            dfs(child, edges, vis);
        }
        st.push(node);
    }
    void revDFS(int node, vector<vector<int>> &rev, vector<bool> &vis, int &c){
        c++;
        vis[node] = true;

        for(auto &child: rev[node]){
            if(!vis[child] && child != -1)
                revDFS(child, rev, vis, c);

        }
        return;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n+1, false);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, edges, vis);
            }
        }

        vector<vector<int>> rev(n);
        for(int i = 0; i<n; i++){
            if(edges[i] != -1)
                rev[edges[i]].push_back(i);
        }
       
        int maxC = 0;
        vis.assign(n, false);
        
        while(!st.empty()){

            int top = st.top(); st.pop();
            if(vis[top]){
                continue;
            }
            
            int c = 0;
            revDFS(top, rev, vis, c);
            cout<<c<<endl;
            maxC = max(maxC, c);
        
        }

        return maxC <= 1 ? -1 : maxC;
    }
};