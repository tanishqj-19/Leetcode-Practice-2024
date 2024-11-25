class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string state = "", k = "123450";
        
        for(int i = 0; i<2; i++){
            for(int j = 0; j < 3; j++){
                state += (board[i][j] + '0');
                
            }
        }


        vector<vector<int>> neighbors = {
            {1, 3},       
            {0, 2, 4},    
            {1, 5},       
            {0, 4},       
            {1, 3, 5},    
            {2, 4}        
        };

        queue<pair<string, int>> q; 
        q.push({state, 0});

        
        unordered_set<string> visited;
        visited.insert(state);
        while(!q.empty()){
            auto [curr, moves] =  q.front(); q.pop();

            if(curr == k){
                return moves;
            }
            int idx = curr.find('0');

            for(auto &nei : neighbors[idx]){
                string next = curr;
                swap(next[idx], next[nei]);
                if(!visited.count(next)){
                    q.push({next, moves + 1});
                    visited.insert(next);
                }
            }
        }


        return -1;

    }
};