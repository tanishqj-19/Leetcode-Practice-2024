class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int curr = 0, n = customers.size(); double avg = 0;
        for(auto &x: customers){
            curr = max(x[0], curr) + x[1];
            avg += (curr - x[0]);
        }

        return (double) avg / n;
    }
};