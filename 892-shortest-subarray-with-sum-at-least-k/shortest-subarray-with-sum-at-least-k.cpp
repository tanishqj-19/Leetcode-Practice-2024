class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        long long sum = 0;
        int minlen = n + 1;

        for(int i =0; i<n; i++){
            sum += nums[i];

            if(sum >= k){
                minlen = min(minlen, i + 1);
            }

            while(!pq.empty() && sum - pq.top().first >= k){
                minlen = min(minlen, i - pq.top().second ); pq.pop();
            }

            pq.push({sum, i});
        }

        return minlen > n ? -1 : minlen;

    }
};