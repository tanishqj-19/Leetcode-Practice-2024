class Solution {
    unordered_set<string> st;

    int solve(string s, int idx){
        if(idx == s.size())
            return 0;
        int cnt = 0;
        for(int end = idx + 1; end <= s.size(); end++){
            string sub = s.substr(idx, end - idx);

            if(st.find(sub) == st.end()){
                st.insert(sub);

                cnt = max(cnt, 1 + solve(s, end));

                st.erase(sub);
            }
        }

        return cnt;
    }
    
public:
    int maxUniqueSplit(string s) {
        return solve(s, 0);
    }
};