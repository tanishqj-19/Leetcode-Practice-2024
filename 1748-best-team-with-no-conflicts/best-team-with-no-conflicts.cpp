class Solution {

    int n;
    

    

    // int bestScore(int i, int prev){
    //     if(i >= n)
    //         return 0;
    //     if(dp[i][prev + 1]  != -1)
    //         return dp[i][prev + 1];

    //     int notPick = bestScore(i + 1, prev);
    //     int pick = 0;

    //     if(prev != -1 && arr[prev].first > arr[i].first && arr[i].second > arr[prev].second){
    //         return dp[i][prev + 1] = max(pick, notPick);
    //     }
    //     pick = arr[i].second + bestScore( i + 1, i);
        

    //     return dp[i][prev + 1] = max(pick, notPick);
        
    // }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();

        vector<int> curr(n + 1, 0), next(n + 1, 0);
        vector<pair<int,int>> arr(n);

        for(int i = 0; i<n; i++){
            arr[i] = {ages[i], scores[i]};
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>> ());

        for(int i = n-1; i>= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                int notPick = next[prev + 1];

                if(prev != -1 && arr[prev].first > arr[i].first && 
                    arr[i].second > arr[prev].second){
                    curr[prev + 1] = notPick;
                }else{
                    curr[prev + 1] = max(notPick, arr[i].second + next[i + 1]);
                }

            }
            next = curr;
        }

        return next[0];
    }
};