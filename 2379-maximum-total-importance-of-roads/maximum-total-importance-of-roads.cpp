class Solution {

    static bool cmp(vector<int> &a, vector<int> &b){
        return a.size() > b.size();
    }
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;

        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++) adj[i].push_back(i);
        for(auto &x: roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        sort(adj.begin(), adj.end(), cmp);

        int y = n;
        unordered_map<int, int> priority;
        for(auto &x: adj){
            priority[x[0]] = y;
            y--;
        }

        for(auto &x: roads){
            ans += (priority[x[0]] + priority[x[1]]);
        }

        return ans;

    }
};