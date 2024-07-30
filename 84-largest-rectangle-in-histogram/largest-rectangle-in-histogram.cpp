class Solution {

    void smaller(vector<int>& arr, vector<int> &next, vector<int> &prev){
        int n = arr.size();
        stack<int> st;


        for(int i=0; i<n; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                next[st.top()] = i-1;
                st.pop();
            }

            if(!st.empty()){
                prev[i] = st.top() + 1;
            }

            st.push(i);
        }
    
    }
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> prev(n, 0);
        vector<int>  next(n, n-1);

        smaller(arr, next, prev);

        // cout<<"Next \n";
        // for(int &i: next)
        // cout<<i<<" ";
        // cout<<"\nPrev \n";
        // for(int &i: prev)
        //     cout<<i<<" ";
    
        int maxarea = 0;
        for(int i=0; i<n; i++){
        
            maxarea = max(maxarea, (next[i] - prev[i] + 1) * arr[i]);
        }

        return maxarea;

    }
};