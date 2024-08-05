class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();

        if(n < k)
            return "";
        map<int, string> track;
        unordered_map<string, int > vis;
        for(int i = 0; i<n;i++){
            if(vis.find(arr[i]) == vis.end()){
                track[i] = arr[i];
                vis[arr[i]] = 1;
            }else{
                vis[arr[i]] = 2;
            }
        }

        for(auto &x: track){
            
            if(vis[x.second] == 1)
                k--;
            if(k == 0)
                return x.second;
        }

        return "";
    }
};