class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        if(n == 1)
            return 0;

        vector<int> flatten(n * n + 1, -1);
        int idx = 1;
        bool left = true;

        for(int i = n-1; i>=0; i--){   
            if(left){
                for(int j = 0; j < n; j++){
                    flatten[idx++] = board[i][j];
                }
            }else{
                for(int j = n-1; j>=0; j--){
                    flatten[idx++] = board[i][j];
                }
            }
            left = !left;
        }

        queue<pair<int, int>> q;

        q.push({0, 1});

        vector<bool> vis(n * n + 1, false);
        vis[1] = true;
        while(!q.empty()){
            auto [moves, node] = q.front(); q.pop();

            if(node == n*n)
                return moves;
            
            for(int i = 1; i<=6; i++){
                int next = node + i;

                if(next > n*n){
                    break;
                }
                if(flatten[next] != -1)
                    next = flatten[next];
                
                if(!vis[next]){
                    vis[next] = true;
                    q.push({moves + 1, next});
                }
                
            }
        }

        

        return -1;
    }
};