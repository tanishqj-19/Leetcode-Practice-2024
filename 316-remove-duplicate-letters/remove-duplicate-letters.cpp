class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        string ans = "";

        stack<char> st;

        unordered_map<char, int> last;

        for(int i = 0; i<n; i++){
            last[s[i]] = i;
        }
        vector<bool> seen(26, false);
        
        for(int i = 0; i<n; i++){
            int idx = s[i] - 'a';

            if(seen[idx]) continue;


            while(!st.empty() && st.top() > s[i] && last[st.top()] > i){
                seen[st.top() - 'a'] = false;
                st.pop();
            }


            st.push(s[i]);
            seen[idx] = true;

        }

        while(!st.empty()){
            ans += st.top();  st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};