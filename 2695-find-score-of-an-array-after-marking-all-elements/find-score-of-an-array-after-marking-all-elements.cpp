class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> vis(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; 


        for(int i = 0; i<n;i++) pq.push({nums[i], i});

        long long score = 0;

        while(!pq.empty()){
            auto [val, idx] = pq.top(); pq.pop();

            if(vis[idx]) continue;
            vis[idx] = true;
            score += val;
            if(idx > 0) 
                vis[idx-1] = true;
            if(idx < n-1)
                vis[idx + 1] = true;
        }

        return score;
    }
};