class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;

        int n = s.size();

        string ans ="";
        for(int i = 0; i<n; i++){

            if(s[i] == '('){
                st.push(i);
            }else {
                if(!st.empty()){
                    int idx = st.top();
                    st.pop();

                    if(st.empty()){
                       ans += s.substr(idx + 1, i -idx-1);
                    }
                }
            }
        }


        return ans;
    }
};