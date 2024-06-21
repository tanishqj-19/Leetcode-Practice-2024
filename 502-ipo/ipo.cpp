class Solution {

    
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;

        int n = profits.size();

        vector<vector<int>> arr(n, vector<int>(2));

        for(int i = 0; i<n; i++){
            arr[i] = {capital[i], profits[i]};
        }

        sort(arr.begin(), arr.end());
        int i = 0 ;
        while(k -- > 0){

            while(i < n && arr[i][0] <= w){
                pq.push(arr[i][1]);
                i++;
            }

            if(pq.empty())
                break;
            
            w += pq.top();
            pq.pop();

        }

        return w;

        
    }
};