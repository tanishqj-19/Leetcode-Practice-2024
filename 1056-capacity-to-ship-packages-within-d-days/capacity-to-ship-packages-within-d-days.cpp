class Solution {

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, n = weights.size();

        for(int  i = 0; i<n; i++){
            low = max(low, weights[i]);
            high += weights[i];
        }

        if(n < days)
            return -1;

        while(low <= high){
            int mid = (low + high) / 2;

            long long  d = 1, temp = 0;

            for(auto i: weights){
                if(temp + i <= mid)
                    temp += i;
                else{
                    temp = i;
                    d++;
                }
            }
        

            if(d <= days)
                high = mid-1;

            else
                low = mid + 1;

        }

        return low;
    }
};