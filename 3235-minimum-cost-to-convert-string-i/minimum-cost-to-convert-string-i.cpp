class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, 1e9));

        for(int i = 0; i<26; i++) adj[i][i] = 0;
        int size = original.size();
        for(int i = 0; i<size; i++){
            int u = original[i] - 'a', v = changed[i] - 'a';

            adj[u][v] = min(adj[u][v], (long long) cost[i]);
        }
        int n = source.size();
        long long totalCost = 0;
        

        for(int k = 0; k<26; k++){
            for(int i = 0; i<26; i++){
                for(int j = 0; j<26; j++){
                    if(adj[i][k] < 1e9 && adj[k][j] , 1e9)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        for(int i = 0; i<n; i++){

            long long curr = adj[source[i] - 'a'][target[i] - 'a'];
            if(curr >= 1e9)
                return -1;
            totalCost += curr;
        }

        return totalCost ;
    }
};