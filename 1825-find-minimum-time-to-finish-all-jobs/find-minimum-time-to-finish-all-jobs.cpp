#define ll long long

class Solution {
    int n, k;
    ll maxWork;
    vector<ll> work;
    

    void fun(vector<int> &jobs, int idx){
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
            fun(jobs, idx + 1);
            work[i] -= jobs[idx];
        }

        return;
    }

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        this->k = k;
        maxWork = LLONG_MAX;
        
        work.resize(k, 0);        
        fun(jobs, 0);
        return maxWork;
    }
};