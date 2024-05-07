class Solution {
    vector<vector<int>> ans;
    

    void dfs(vector<vector<int>> &graph, int node, int target, vector<int> temp){
        temp.push_back(node);
        if(node == target){
            
            ans.push_back(temp);
            return;
        }else{
            for(int &v: graph[node]){
                dfs(graph, v, target, temp);
            }
                
        }
        temp.pop_back();
        return;

    
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        int n = graph.size();

        dfs(graph, 0, n-1, {});

        return ans;
    }
};