class Trie{
public:
    int count;
    Trie* letters[26];

};

void buildTrie(string &s, Trie* node){

    for(char &c: s){
        if(node->letters[c-'a'] == NULL){
            node->letters[c-'a'] = new Trie();   
        }

        node = node->letters[c-'a'];
        node->count = node->count + 1;
        
    }
}

void solve(string &s, Trie* node, int & cnt){
    for(auto &ch: s){
        node = node->letters[ch - 'a'];
        cnt += node->count;
    }
    return;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* node = new Trie();

        for(auto &str: words){
            buildTrie(str, node);
        }

        vector<int> sum;
        int c = 0;
        for(string &s: words){
            c = 0;
            solve(s, node, c);
            sum.push_back(c);
        }

        return sum;
    }

};