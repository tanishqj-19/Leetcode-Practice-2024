class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        
        vector<int> arr(m, 0);
        int maxi = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            }

            
            int area = largestRectangleArea(arr);
            maxi = max(maxi, area);

                
            
        }

        return maxi;

       
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> prev(n, 0);
        vector<int>  next(n, n-1);

        smaller(arr, next, prev);

        int maxarea = 0;
        for(int i=0; i<n; i++){
        
            maxarea = max(maxarea, (next[i] - prev[i] + 1) * arr[i]);
        }

        return maxarea;

    }

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
};