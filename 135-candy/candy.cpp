class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();

        int i = 1;
        
        vector<int> candies(n, 0);
        candies[0] = 1; 

        while(i < n){
            if(rating[i] > rating[i-1])
                candies[i] = candies[i-1] + 1;
            else
                candies[i] = 1;
            i++;
        }

        i = n-2;
        if(candies[n-1] == 0)
            candies[n-1] = 1;
        while(i >= 0){
            if(rating[i] > rating[i + 1])
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            else if(candies[i] == 0)
                candies[i] = 1;
            i--;
            
        }

        // for(int &i: candies) cout<<i<<" ";

        int sum = accumulate(candies.begin(), candies.end(), 0);

        return sum;
    }
};