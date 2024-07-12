class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n + 1];

        for(auto & x: dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        

        vector<int> color(n + 1, -1);

        for(int i = 1; i<=n; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);

                color[i] = 1;

                while(!q.empty()){
                    int node = q.front(); q.pop();

                    for(auto &neighbour: adj[node]){
                        if(color[neighbour] == -1){
                            color[neighbour] = 1- color[node];
                            q.push(neighbour);
                        }else if(color[neighbour] == color[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};