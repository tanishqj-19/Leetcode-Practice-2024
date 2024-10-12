class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;


        for(auto & interval: intervals){
            if(pq.empty() || pq.top() >= interval[0])
                pq.push(interval[1]);
            else{
                int x = pq.top(); pq.pop();
                pq.push(interval[1]);
            }
        }

        return pq.size();
    }
};