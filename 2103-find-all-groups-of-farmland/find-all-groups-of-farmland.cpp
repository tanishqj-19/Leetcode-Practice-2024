class Solution {

    void dfs(int i, int j,vector<vector<int>>& land,vector<vector<bool>> &vis,vector<int> &temp){
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size()|| land[i][j] == 0 || vis[i][j])
            return ;

        vis[i][j] = true;

        if(temp[2] != -1){
            if(i >= temp[2] && j >= temp[3]){
                temp[2] = i;
                temp[3] = j;
            }
        }else{
            temp[2] = i;
            temp[3] = j;
        }

        
        dfs(i - 1, j, land, vis, temp);
        dfs(i, j-1, land, vis, temp);
        dfs(i + 1, j, land, vis, temp);
        dfs(i , j+1, land, vis, temp);
        


        
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();

        
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    vector<int> temp(4, -1);
                    temp[0] = i;
                    temp[1] = j;
                    dfs(i, j, land, vis, temp);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};