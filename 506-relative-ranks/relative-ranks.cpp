class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> maxheap;

        for(int i=0; i<score.size(); i++){
            maxheap.push({score[i], i});
        }

        vector<string> res(score.size());

        for(int i=0; i<score.size(); i++){
            pair<int, int> top = maxheap.top();
            maxheap.pop();
            if(i == 0){
                res[top.second] = "Gold Medal";
            }else if (i == 1){
                res[top.second] = "Silver Medal";
            }else if(i == 2){
                res[top.second] = "Bronze Medal";
            }else
                res[top.second] = to_string(i + 1);

        }

        return res;
    }
};