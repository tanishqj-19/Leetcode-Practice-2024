class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9 + 7;

         priority_queue <int, vector<int>, greater<int>> pq;

        for(int &i: nums) pq.push(i);

        while(k-- > 0){
            int x = pq.top(); pq.pop();
            x++;
            pq.push(x);
        }

        long long int   maxi = 1;

        while(!pq.empty()){
            int x = pq.top(); pq.pop();

            maxi = (maxi * x) % mod;
        }

        return maxi;
    }
};