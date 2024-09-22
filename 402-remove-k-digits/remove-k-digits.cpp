class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if(n <= k) return "0";


        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && k > 0 && num[i] < num[st.top()]){
                k--;
                st.pop();
            }
            st.push(i);

            if(st.size() == 1 && num[st.top()] == '0') st.pop();
        }

        while(!st.empty() && k > 0){
            k--; st.pop();
        }
        string cleanNum = "";

        while(!st.empty()){
            cleanNum += num[st.top()]; st.pop();
        }
        if(cleanNum.empty())
            return "0";

        reverse(cleanNum.begin(), cleanNum.end());

        return cleanNum;
    }
};