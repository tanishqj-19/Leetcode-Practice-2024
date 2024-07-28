class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n + 1];

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        vector<pair<int, int>> dis(n + 1);

        for(int i = 1; i<=n; i++) dis[i] = {1e9, 1e9};
        q.push({0, 1});
        dis[0].first = 0;

        while(!q.empty()){
            auto [w, node] = q.front(); q.pop();

            for(auto &v: adj[node]){
                int d = w + 1;

                if(d < dis[v].first){
                    dis[v].second = dis[v].first;
                    dis[v].first = d;
                    q.push({d, v});
                }else if(d < dis[v].second && d > dis[v].first){
                    q.push({d, v});
                    dis[v].second = d;
                }
            }
        }
        
        int duration = dis[n].second;
        int secondTime = 0;
        for(int i= 0 ; i<duration; i++){
            if((secondTime / change) % 2 == 1){
                secondTime += (change - (secondTime % change));
            }
            secondTime += time;
        }

        



        return secondTime;



    }
};