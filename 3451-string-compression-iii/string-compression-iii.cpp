class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        if(n == 1){
            string ans = "1";
            ans += word.back();
            return ans;
        }

        string comp = "";

        int cnt = 1;
        char curr = word[0];

        for(int i = 1; i<n; i++){
            if(word[i] == word[i-1] && cnt < 9){
                cnt++;
            }else{
                comp += to_string(cnt);
                comp += curr;
                curr = word[i];
                cnt = 1;
            }
        }

        comp += to_string(cnt);
        comp += curr;

        return comp;
    }
};