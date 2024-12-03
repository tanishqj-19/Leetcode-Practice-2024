class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans  = "";
        int n = s.size(), m = spaces.size();
        int j = 0;
        for(int i = 0; i<n; i++){
            if(j < m && i == spaces[j]){
                ans += " ";
                ans += s[i]; j++;
            }else{
                ans += s[i];
            }
        }


        return ans;
    }
};