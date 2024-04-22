class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        


        unordered_set<string> s;

        for(string &ss: wordList){
            s.insert(ss);
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, d] = q.front(); q.pop();

            if(endWord == word){
                return d;
            }

            for(int i=0; i<word.size(); i++){
                char ori = word[i];

                for(char c = 'a' ; c <= 'z'; c++){
                    word[i] = c;
                    if(s.find(word) != s.end()){
                        q.push({word, d + 1});
                        s.erase(word);
                    }
                }
                word[i]  = ori;
            }
        }

        return 0;
    }
};