class Solution {
    int n;
    int dp[1001];
    int f(vector<vector<int>> &books, int i, int w){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int notPick = f(books, i + 1, w);
        int cw = 0, ch = 0, minH = 1e9;
        for(int idx = i; idx < n; idx++){
            if(cw + books[idx][0] > w)
                break;
            cw += books[idx][0];
            ch = max(ch, books[idx][1]);

            minH = min(minH, ch + f(books, idx + 1, w));
        }

        return dp[i] = minH;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int w) {
        n = books.size();
        memset(dp, -1, sizeof(dp));

        return f(books, 0, w);
    }
};