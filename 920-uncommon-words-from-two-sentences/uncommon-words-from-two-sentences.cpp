class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        unordered_map<string, int> freq;

        string word;
        while(ss >> word){
            freq[word]++;
        }

        stringstream ss2(s2);
        while(ss2 >> word){
            freq[word]++;
        }

        vector<string> ans;

        for(auto &x: freq){
            if(x.second == 1)
                ans.push_back(x.first);
        }

        return ans;
    }
};