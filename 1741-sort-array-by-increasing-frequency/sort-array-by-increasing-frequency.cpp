class Solution {
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> count;

        for(int &n: nums) count[n]++;

        vector<pair<int, int>> vec;

        for(auto x: count){
            vec.push_back({x.first, x.second});
        }

        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans;
        for(int i=0; i<vec.size(); i++){
            while(vec[i].second--> 0){
                ans.push_back(vec[i].first);
            }
        }
        return ans;





    }
};