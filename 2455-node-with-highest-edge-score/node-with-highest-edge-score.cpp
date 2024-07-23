#define ll long long
class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int n = edges.size();
        vector<ll> sum(n, 0);
        ll maxSum = 0;
        for(int i = 0; i<n; i++){
            sum[edges[i]] += i;
            maxSum = max(maxSum, sum[edges[i]]);
        }
        
        for(int i = 0; i<n; i++){
            if(sum[i] == maxSum)
                return i;
        }

        return -1;

        

    }
};