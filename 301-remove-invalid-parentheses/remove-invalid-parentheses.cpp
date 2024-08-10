class Solution {

    int countInvalid(string &s){
        int open = 0, close = 0;

        for(char &c: s){
            if(c == '('){
                open++;
            }else if(c == ')'){
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }

        return open + close;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans; 
        int n = s.size();  
        int invalid = countInvalid(s);
        
        ways(s, invalid, ans);

        return ans;

      

    }
private:
    unordered_set<string> myset;
    void ways(string s, int k, vector<string> &ans){
        if(k < 0)
            return;
        if(k == 0){
            int invalid = countInvalid(s);
            if(invalid == 0)
                ans.push_back(s);
            return;
        }

        for(int i = 0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            string curr = left + right;

            if(myset.count(curr) <= 0){
                myset.insert(curr);
                ways(curr, k-1, ans);
            }
        }
    }
};