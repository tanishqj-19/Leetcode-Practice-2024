class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        string ans = "";
        stack<unordered_map<string, int>> st;

        int i = 0;

        while(i < n){
            if(s[i] == '('){
                st.push(mp);
                mp.clear();
                i++;
            }else if(s[i] == ')'){
                auto temp = mp;
                mp = st.top(); st.pop();
                i++;
                int m = 0;
                while(i < n && isdigit(s[i])){
                    m = (m * 10) + s[i] - '0';
                    i++;
                }
                if(m == 0) m = 1;

                for(auto &x: temp){
        
                    mp[x.first] += (x.second * m);
                }
            }else{
                string atom = "";
                atom += s[i++];
                while(i < n && islower(s[i])){
                    atom += s[i];
                    i++;
                }

                int c = 0;

                while(i < n && isdigit(s[i])){
                    c = (c * 10) + s[i] - '0';
                    i++;
                }

                if(c == 0)
                    c= 1;
                mp[atom] += c;
            }
        }

        vector<pair<string, int>> elements(mp.begin(), mp.end());
        sort(elements.begin(), elements.end());

        for (auto& p : elements) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }

        return ans;
    }
};