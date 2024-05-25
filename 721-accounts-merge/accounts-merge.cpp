class Solution {

    vector<int> parent, rank;

    int find(int node){
        if(parent[node] == node)
            return node;
        return find(parent[node]);
    }

    void unionRank(int x, int y){
        int upx = find(x), upy = find(y);

        if(upx == upy)
            return;
        if(rank[upx] > rank[upy]){
            parent[upy] = upx;
        }else if(rank[upx] < rank[upy]){
            parent[upx] = upy;
        }else{
            parent[upx] = upy;
            rank[upx]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        unordered_map<string, int> nodeMap;
        rank.resize(n, 0);
        parent.resize(n);

        for(int i = 0; i<n; i++)
            parent[i] = i;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string s = accounts[i][j];

                if(nodeMap.find(s) != nodeMap.end()){
                    unionRank(nodeMap[s], i);
                }else{
                    nodeMap[s] = i;
                }
            }
        }


        vector<vector<string>>  mp(n);

        for(auto x: nodeMap){
            int ulti = find(x.second);
            mp[ulti].push_back(x.first);
        }

        vector<vector<string>> merged;
        int j = 0;
        for(int i = 0; i<n; i++){

            if(mp[i].empty()) continue;
            sort(mp[i].begin(), mp[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &x: mp[i]) temp.push_back(x);

            merged.push_back(temp);
           
        }


        return merged;






        
    }
};