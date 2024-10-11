class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int k = times[targetFriend][0];
        sort(times.begin(), times.end());

        int maxEnd = 0;

        priority_queue<int, vector<int>, greater<int>> time;

        for(int i =0; i<n; i++) time.push(i);

        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;

        for(auto &a: times){
            int arrival = a[0], departure = a[1];

            while(!pq.empty() && pq.top().first <= arrival){
                time.push(pq.top().second); pq.pop();
            }

            int currChair = time.top(); time.pop();
        
            pq.push({a[1], currChair});
            if(a[0] == k){
                return currChair;
            }
        }
        return 0;





    }
};