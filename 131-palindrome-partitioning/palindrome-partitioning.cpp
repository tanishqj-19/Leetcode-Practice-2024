class Solution {

    bool check(string &s, int i, int j){
        while(i <=j){
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }

    void solve(string &s, int idx, vector<vector<string>> &res, vector<string> pali){
        if(idx == s.length()){
            res.push_back(pali);
            return;
        }

        for(int j= idx; j<s.length(); j++){
            if(check(s, idx, j)){
                string temp = s.substr(idx, j-idx+1);
                pali.push_back(temp);

                solve(s, j+1, res, pali);
                pali.pop_back();
                

            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        solve(s, 0, ans, partition);
        return ans;
    }
};