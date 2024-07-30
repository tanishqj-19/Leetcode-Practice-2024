class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> chars = {'A', 'C', 'G', 'T'};

        unordered_set<string> s;

        for(auto &i: bank) s.insert(i);

        if(s.find(endGene) == s.end())
            return -1;

        queue<pair<int, string>> q;

        q.push({0, startGene});
        unordered_map<string, bool> vis;
        vis[startGene] = true;


        while(!q.empty()){
            auto [dis, curr] = q.front(); q.pop();

            if(curr == endGene)
                return dis;

            for(int i = 0; i<curr.size(); i++){
                string ori = curr;

                for(auto &t: chars){
                    curr[i] = t;

                    if(s.find(curr) != s.end() && !vis[curr]){
                        q.push({dis + 1, curr});
                        vis[curr] = true;
                    }
                }

                curr = ori;


            }
        }

        return -1;
    }
};