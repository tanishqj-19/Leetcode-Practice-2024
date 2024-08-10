class Solution {
    bool isValid(string &s){
        int cnt = 0;
        for(char &c: s){
            if(c == '(')
                cnt++;
            else if(c == ')'){
                if(cnt > 0)
                    cnt--;
                else
                    return false;

            }
        }

        return cnt == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        unordered_map<string, bool> vis;

        queue<string> q;
        q.push(s);
        vis[s] = true;

        bool found = false;
        vector<string> ans;

        while(!q.empty()){
            s = q.front(); q.pop();

            if(isValid(s)){
                ans.push_back(s);
                found = true;
            }
            if(found) continue;

            for(int i = 0; i <s.size(); i++){
                if(s[i] != '(' && s[i] != ')') continue;
                string left = s.substr(0, i), right = s.substr(i + 1);
                string newS = left + right;
                if(vis[newS] == false){
                    q.push(newS);
                    vis[newS] = true;
                }
            }

        
        
        }
        return ans;
    }
};