class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> chars = {'A', 'C', 'G', 'T'};

        unordered_set<string> s{bank.begin(), bank.end()};

        if(s.find(endGene) == s.end())
            return -1;

        queue<pair<int, string>> q;

        q.push({0, startGene});
        
        while(!q.empty()){
            auto [dis, curr] = q.front(); q.pop();

            if(curr == endGene)
                return dis;
            s.erase(curr);

            for(int i = 0; i<curr.size(); i++){
                string ori = curr;

                for(auto &t: chars){
                    curr[i] = t;

                    if(s.find(curr) != s.end()){
                        q.push({dis + 1, curr});
                    }
                }

                curr = ori;


            }
        }

        return -1;
    }
};