class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();


        queue<int> q;

        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();q.pop();

            for(auto x: rooms[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                }
                    
            }
        }

        for(int  i = 0 ; i <n; i++){
            if(!vis[i])
                return false;
        }

        return true;
    }
};