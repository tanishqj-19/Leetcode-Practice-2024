#define ll long long
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<ll,ll> sum;
        ll maxSum = 0;
        for(int i = 0; i<edges.size(); i++){
            sum[edges[i]] += i;
            maxSum = max(maxSum, sum[edges[i]]);
        }
        ll node = edges.size();

        for(auto &x: sum){
            if(x.second == maxSum){
                node = min(node, x.first);
            }
        }

        return node;

        

    }
};