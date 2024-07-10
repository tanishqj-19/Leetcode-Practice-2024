class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        stack<string> st;

        for(string &s: logs){
            
            if(s == "./") continue;
            
            if(s == "../"){
                if(!st.empty()) st.pop();
            }
            else
                st.push(s);
        }

        return st.size();
    }
};