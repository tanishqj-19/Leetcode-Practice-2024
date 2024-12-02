class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int len = searchWord.size();

        int i = 1;
        stringstream ss(sentence);

        string word;

        while(ss >> word){
            string sub = word.substr(0, len);

            if(sub == searchWord)
                return i;
            i++;
        }

        return -1;

        
    }
};