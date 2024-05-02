class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        
        for(auto &x: flights){
            adj[x[0]].push_back({x[1], x[2]});
            
        }
        
        queue< vector<int> > q;
        
        q.push({0 ,src, 0});
        
        vector<int> dis(n , 1e9);
        dis[src] = 0;
        
        while(!q.empty()){
            vector<int> vec = q.front(); q.pop();
            
            int stop = vec[0], u = vec[1], d = vec[2];
            if(stop > K) continue;
            
            
            
            
            for(auto x: adj[u]){
                int v = x.first, w = x.second;
                
                if(dis[v] > d + w){
                    dis[v] = d + w;
                    q.push({stop + 1, v, dis[v]});
                }
            }
        }
        
        return dis[dst] == 1e9 ? -1 : dis[dst];
        
    }
};