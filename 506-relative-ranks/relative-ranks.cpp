class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        

        int maxi = *max_element(score.begin(), score.end());

        vector<int> idx(maxi + 1, -1);
        int n = score.size();


        for(int  i = 0; i <n ; i++){
            idx[score[i]] = i;
        }

        vector<string> ans(n);
        int rank = 1;
        vector<string> temp = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        for(int  i = maxi; i>=0; i--){
            if(idx[i] != -1){
                
                if(rank < 4){
                    ans[idx[i]] = temp[rank-1];
                }else{
                    ans[idx[i]] = to_string(rank);
                }
                rank++;
            }

        }

        return ans;
    }
};