#define ll long long

class Solution {
    unordered_map<int, vector<pair<ll, int>>> adj;
    
    
    ll shortestPath(int src, int des, vector<vector<ll>> &dp){
        if(dp[src][des] != -1)
            return dp[src][des];
        if(src == des)
            return 0;
        queue<pair<ll, ll>> pq;
        pq.push({0, src});
        vector<ll> dist(26, 1e9);
        dist[src]  = 0;
        

        while(!pq.empty()){
            auto [w, node] = pq.front();pq.pop();

            
            for(auto &t: adj[node]){
                ll d = t.first, next  = t.second;
                if(d + w < dist[next]){
                    pq.push({d + w, next});
                    dist[next] = d + w;
                }
            }
        }

        
        return dp[src][des] = dist[des] == 1e9 ? -1: dist[des];
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        for(int i = 0; i<original.size(); i++){
            adj[original[i] - 'a'].push_back({cost[i], (changed[i] - 'a')});
        }

        ll totalCost = 0;
        vector<vector<ll>> dp(26, vector<ll>(26, -1));
        for(int i = 0; i<source.size(); i++){
            if(source[i] == target[i]) continue;
            int src = source[i] - 'a', dest = target[i] - 'a';
            ll currCost = shortestPath(src, dest, dp);
            if(currCost == -1)
                return -1;
            else
                totalCost += currCost;
        }

        return totalCost;
    }
};