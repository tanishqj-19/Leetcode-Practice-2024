class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr);

        sort(ans.begin(), ans.end());

        unordered_map<int, int> r;

        for(int &i: ans){
            r.emplace(i, r.size() + 1);
        }

        for(int i = 0; i<ans.size(); i++){
            ans[i] = r[arr[i]];
        }

        return ans;
    }
};