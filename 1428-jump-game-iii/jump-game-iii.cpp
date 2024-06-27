class Solution {
    int s = -1;
    vector<int> vis;
    bool solve(vector<int> &arr, int i, int n){

        if(i < 0 || i >= n || vis[i])
            return false;
        if(s == -1)
            s = i;
        vis[i] = true;
        if(arr[i] == 0)
            return true;
        
        return solve(arr, i - arr[i], n) || solve(arr, i + arr[i], n);
        
        

    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vis.resize(n, false);
        // s = start;
        return solve(arr, start, n);
    }
};