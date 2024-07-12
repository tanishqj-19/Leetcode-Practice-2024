class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        vector<char> st;
        int first_score = x, second_score = y;

        string f1 = "ab", f2 = "ba";
        if(y > x){
            swap(first_score, second_score);
            f1 = "ba"; f2 = "ab";
        }
        int score = 0;
        for(int i =0; i<n; i++){
            if(!st.empty() && st.back() == f1[0] && s[i] == f1[1]){
                st.pop_back();
                score += first_score;
            }else
                st.push_back(s[i]);
        }
        stack<char> temp;
        for(char &c : st){
            if(!temp.empty() && c == f2[1] && temp.top() == f2[0] ){
                temp.pop();
                score += second_score;
            }else{
                temp.push(c);
            }
        }

        return score;
    }
};