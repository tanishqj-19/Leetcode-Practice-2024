class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        int maxi = 0;


        while(low <= high){
            int mid = (low + high)/2;

            long long child = 0;

            for(int i = 0; i<n; i++){
                child = child + (long long) candies[i] / mid;

            }
            
            if(child >= k){
                
                maxi = max(mid, maxi);
                low = mid + 1;
            }else
                high = mid - 1;
        }

        return maxi;
    }
};