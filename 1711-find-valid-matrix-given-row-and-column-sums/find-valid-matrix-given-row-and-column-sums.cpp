class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> row, col;

        for(int i = 0; i<n; i++) row.push({rowSum[i], i});
        for(int i = 0; i<m; i++) col.push({colSum[i], i});

        while(!row.empty() && !col.empty()){
            int r = row.top().second, rsum  = row.top().first; row.pop();
            int c = col.top().second, csum = col.top().first; col.pop();

            int val = min(rsum, csum);

            mat[r][c] = val;
            rsum -= val, csum -=val;
            if(rsum > 0)
                row.push({rsum, r});
            if(csum > 0)
                col.push({csum, c});

        }

        return mat;

    }
};