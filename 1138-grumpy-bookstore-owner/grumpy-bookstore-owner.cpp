class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0, add = 0, maxAdd = 0;
        for(int i = 0; i<n; i++){

            if(grumpy[i] == 0)
                sum += customers[i];
            if(grumpy[i]) add += customers[i];

            if(i >= minutes){
   
                add -= (grumpy[i-minutes] * customers[i - minutes] );
            }

            maxAdd = max(maxAdd, add);
        }

        return sum + maxAdd;
    }
};