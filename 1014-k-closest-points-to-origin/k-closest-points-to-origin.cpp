class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int, int>>>pq;

        for(auto& point: points){
            
            long long x = point[0], y = point[1];
            long long d = x * x + y * y;

            pq.push({d, {x, y}});

            if(pq.size() > k)
                pq.pop();
            
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};