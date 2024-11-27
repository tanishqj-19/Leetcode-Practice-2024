

class Solution {
    int dijkstra(int V, vector<int> adj[], int S)
    {

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        
        vector<int> distTo(V, INT_MAX);

    
        distTo[S] = 0;
        pq.push({0, S});

        
        while (!pq.empty())
        {
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();

           
            for (auto v : adj[node])
            {
                
                if (1 + w < distTo[v])
                {
                    distTo[v] = 1 + w;

                    pq.push({1 + w, v});
                }
            }
        }
        
        return distTo[V-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int src = 0, dest = n-1;

        vector<int> adj[n];

        for(int i = 0; i<n; i++){
            if(i < n - 1)
            adj[i].push_back(i + 1);
        }
        vector<int> cost;

        for(auto &q: queries){
            int u = q[0], v = q[1];

            adj[u].push_back(v);

            cost.push_back(dijkstra(n, adj, 0));

            
        }

        return cost;


    }
};