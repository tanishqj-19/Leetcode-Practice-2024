class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> st;
        string ans = "";
        for(int i = 0; i <n; i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                int start = st.top(); st.pop();
                reverse(s.begin() + start, s.begin() + i);
                
            }
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == ')') continue;
            ans += s[i];
        }

        return ans;
    }
};