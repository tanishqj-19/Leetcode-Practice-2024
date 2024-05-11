class Solution {
    static bool cmp(pair<double, double> & a, pair<double, double> & b){
        return a.first < b.first;
    }
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = 0;
        int  n = quality.size();

        vector<pair<double, double>> arr(n);
        
        for(int i=0; i<n; i++){
            arr[i].first = (double) wage[i]/quality[i];
            arr[i].second = (double) quality[i];
        }

        sort(arr.begin(), arr.end(), cmp);
        

        priority_queue<double> pq;
        double minSum = DBL_MAX;
        for(auto x: arr){
            ans += x.second;
            pq.push(x.second);

            if(pq.size() > k){
                ans -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                minSum = min(minSum, x.first * ans);
            }
        }


        return minSum;
    }
};