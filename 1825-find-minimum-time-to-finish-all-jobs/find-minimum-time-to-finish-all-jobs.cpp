#define ll long long

class Solution {
    int n;
    ll maxWork;
    

    void fun(vector<int> &jobs, int &k, int idx, vector<ll> & work){
        if(idx == n){
            ll load = *max_element(work.begin(), work.end());
            maxWork = min(maxWork, load);
            return;
        }

        unordered_set<ll> s;

        for(int i = 0; i<k; i++){
            if(s.count(work[i]) > 0 || work[i] + jobs[idx] >= maxWork) continue;

            s.insert(work[i]);
            work[i] += jobs[idx];
            fun(jobs, k, idx + 1, work);
            work[i] -= jobs[idx];
        }

        return;
    }

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        maxWork = LLONG_MAX;
        if(n == k)
            return *max_element(jobs.begin(), jobs.end());
        
        vector<ll> work(k, 0);
        
        fun(jobs, k, 0, work);
        return maxWork;
    }
};