class Solution {

    unordered_map<string, int> dis;
    vector<vector<string>> ans;
    string start;
    void dfs(string word, vector<string> &path){
        if(word == start){
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        int sz = word.size();
        int step = dis[word];
        for(int i=0; i<sz; i++){
            char ori = word[i];
            for(char c='a'; c <= 'z'; c++){
                word[i] = c;

                if(dis.find(word) != dis.end() && dis[word] + 1 == step){
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }

            word[i] = ori;
        }

        


    }

    vector<vector<string>> bfs(unordered_set<string>& list, string &word,  string &end){
        queue<string> q;

        q.push({word});
        dis[word] = 1;
        start = word;
        list.erase(word);
       
        int sz = word.size();
        while(!q.empty()){
            string curr = q.front(); q.pop();
            int d = dis[curr];

            if(curr == end)
                break;
            for(int i=0; i<sz; i++){
                char o = curr[i];
                for(char c='a'; c <= 'z'; c++){
                    curr[i] = c;
                    if(list.count(curr)){
                        q.push(curr);
                        list.erase(curr);
                        dis[curr] = d + 1;
                    }
                }
                curr[i] = o;
            }
        }

        if(dis.find(end) != dis.end()){
            vector<string> path;
            path.push_back(end);
            dfs(end, path);
        }

        return ans;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        
        return bfs(list, beginWord, endWord);

    }
};