#define pp pair<int, int> 

class Solution {

    bool bfs(int node, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(node);


        while(!q.empty()){
            int root = q.front(); q.pop();

            for(auto &nei: graph[root]){
                if(color[nei] == -1){
                    color[nei] = 1 - color[root];
                    q.push(nei);
                }else if(color[nei] == color[root])
                    return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        

        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};