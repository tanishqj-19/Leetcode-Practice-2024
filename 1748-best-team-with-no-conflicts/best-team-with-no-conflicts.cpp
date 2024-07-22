class Solution {

    int n;
    int dp[1001][1002];

    vector<pair<int,int>> arr;

    int bestScore(int i, int prev){
        if(i >= n)
            return 0;
        if(dp[i][prev + 1]  != -1)
            return dp[i][prev + 1];

        int notPick = bestScore(i + 1, prev);
        int pick = 0;

        if(prev != -1 && arr[prev].first > arr[i].first && arr[i].second > arr[prev].second){
            return dp[i][prev + 1] = max(pick, notPick);
        }
        pick = arr[i].second + bestScore( i + 1, i);
        

        return dp[i][prev + 1] = max(pick, notPick);
        
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();

        memset(dp, -1, sizeof(dp));
        arr.resize(n);

        for(int i = 0; i<n; i++){
            arr[i] = {ages[i], scores[i]};
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>> ());

        return bestScore( 0, -1);
    }
};