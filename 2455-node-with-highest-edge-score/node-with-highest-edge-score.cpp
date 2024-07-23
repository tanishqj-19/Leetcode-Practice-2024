#define ll long long
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,ll> sum;
        ll maxSum = 0;
        for(int i = 0; i<edges.size(); i++){
            sum[edges[i]] += i;
            maxSum = max(maxSum, sum[edges[i]]);
        }
        int  node = edges.size();

        for(auto &x: sum){
            if(x.second == maxSum){
                node = min(node, x.first);
            }
        }

        return (int) node;

        

    }
};