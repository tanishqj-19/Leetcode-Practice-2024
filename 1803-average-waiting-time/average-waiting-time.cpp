class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n  = customers.size();

        if(n == 1)
            return customers[0][1] / 1.0;

        double avg = customers[0][1] / 1.0;
        int prevWait = customers[0][1] + customers[0][0];

        for(int i = 1; i<n; i++){
            if(prevWait >= customers[i][0]){
                int curr = prevWait + customers[i][1] - customers[i][0];
                avg += curr;
                prevWait = (prevWait + customers[i][1]);
            }else{
                avg += customers[i][1];
                prevWait = (customers[i][0] + customers[i][1]);
            }
        }

        return (double) avg / n;

        
    }
};