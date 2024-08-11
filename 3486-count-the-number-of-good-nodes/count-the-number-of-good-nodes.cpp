class Solution {

    int dfs(int node, vector<vector<int>>& adj, vector<int> &subtree){
        int size = 1;

        for(int x: adj[node]){
            size += dfs(x, adj, subtree);
        }
        subtree[node] = size;
        return size;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> adj[n + 1];

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);


        }

        vector<int> subtree(n, 0), vis(n, 0);
        vector<vector<int>> newTree(n);
        buildTree(0, adj, newTree, vis);
        dfs(0, newTree, subtree);
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> sz;
            for (int child : newTree[i]) {
                sz.insert(subtree[child]);
            }

            if (sz.size() <= 1) {
                cnt++;
            }
        }

        return cnt;

    }

     void buildTree(int root, vector<int>tree[], vector<vector<int>>& newTree, vector<int>& visited) {
        visited[root] = true;
        for (int child : tree[root]) {
            if (!visited[child]) {
                newTree[root].push_back(child);
                buildTree(child, tree, newTree, visited);
            }
        }
    }
};