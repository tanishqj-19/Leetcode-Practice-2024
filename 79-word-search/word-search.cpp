class Solution {
    int n, m;
    bool isValid(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    vector<int> dir = {0, -1, 0, 1, 0};
    bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j, vector<vector<int>>& vis) {
        if (index == word.size()) return true; 
        if (!isValid(i, j) || vis[i][j] || board[i][j] != word[index]) return false; 
        vis[i][j] = 1; 
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            if (backtrack(board, word, index + 1, ni, nj, vis))
                return true; 
        }
        vis[i][j] = 0; 
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j =0 ; j<m; j++){

                if(board[i][j] != word[0]) continue;
                vector<vector<int>> vis(n ,vector<int>(m, 0));

                if(backtrack(board, word, 0, i, j, vis))
                    return true;
            }
        }

        return false;
    }
};