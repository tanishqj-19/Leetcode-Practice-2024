class Solution {

private:
    void backtrack(const vector<int> candidates, int target, int index,
        vector<vector<int>> &ans, vector<int> &temp){
        
        if(target < 0) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) return;
            if(i> index && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1, ans, temp);
            temp.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> comb; vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, comb, temp);
        return comb;
    }
};