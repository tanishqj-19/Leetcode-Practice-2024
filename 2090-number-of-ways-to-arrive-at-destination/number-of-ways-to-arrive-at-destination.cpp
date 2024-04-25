class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long>>> adj(n);


        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

       

        priority_queue< pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>> > pq;
        vector<long> dis(n, LONG_MAX);
        vector<long> ways(n, 0);

        pq.push({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        
        while(!pq.empty()){
            auto [d, x] = pq.top(); pq.pop();

            if(d > dis[x]) continue;

            for(auto [v, wt]: adj[x]){
                

                if(dis[v] > wt + d){
                    dis[v] = wt + d;
                    ways[v] = ways[x];
                    pq.push({dis[v], v});
                }else if(dis[v] == wt + d){
                    ways[v] = (ways[v] + ways[x]) % MOD;
                }
            }
        }

        return ways[n-1];

    }
};