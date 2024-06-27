class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int n = adj.size();
        for(auto x: adj){
            if(x.second.size() == n-1)
                return x.first;
        }

        return -1;
    }
};