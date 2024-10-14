class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0; 
        priority_queue<int> pq(nums.begin(), nums.end()); 
        while (k--) {
            int val = pq.top(); pq.pop();
            ans += val; 
            pq.push((val+2)/3); 
        }
        return ans; 
    }
};