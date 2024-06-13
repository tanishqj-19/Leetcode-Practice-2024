class Solution {
public:
    int maxDepth(string s) {
        int maxD = 0;

        stack<char> st;

        for(char &c: s){
            if(c == '('){
                st.push(c);
                int x = st.size();
                maxD = max(maxD, x);
            }else if(c == ')')
                if(!st.empty()) st.pop();
            else{
                
            }

        }

        return maxD;
    }
};