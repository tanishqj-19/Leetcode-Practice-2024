class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        
        stack<int> st;

        for(int i = 0; i<n; i++){

            while(!st.empty() && heights[st.top()] < heights[i]){
                answer[st.top()]++;
                st.pop();
            }

            if(!st.empty())
                answer[st.top()]++;
            st.push(i);
        }

        return answer;



    }
};