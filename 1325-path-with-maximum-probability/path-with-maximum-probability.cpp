class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);

        for(int i=0; i<edges.size(); i++){
            vector<int> x = edges[i];
            adj[x[0]].push_back({x[1], succProb[i]});
            adj[x[1]].push_back({x[0], succProb[i]});

        }

        priority_queue< pair<double, int> > pq;

        pq.push({double(1.0), start});

        vector<double> prob(n, -1e9);
        prob[start] = (double) 1.0;
        
        double maxi = 0.00;
        while(!pq.empty()){
            pair<double, int> x = pq.top(); pq.pop();
            double d = x.first;
            int node = x.second;

            if(node == end){
                if(d > maxi)
                    maxi = d;
                
            }
            for(auto y: adj[node]){
                int v = y.first;
                double wt = (double) y.second;
                double dis = (double) wt * d;
                if(prob[v] < dis ){
                    prob[v] = dis;
                    pq.push({dis, v});
                }
            }
        }


        return maxi;



    }
};