class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        

        string comp = "";

        int cnt = 1;
        // char curr = word[0];

        for(int i = 1; i<n; i++){
            if(word[i] == word[i-1] && cnt < 9){
                cnt++;
            }else{
                comp += to_string(cnt);
                comp += word[i-1];
                cnt = 1;
            }
        }

        comp += to_string(cnt);
        comp += word.back();

        return comp;
    }
};