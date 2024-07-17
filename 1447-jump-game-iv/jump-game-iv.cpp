
class Solution {
    

    
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1 || n == 2)
            return n-1;
        if(arr[0] == arr[n-1])
            return 1;


        unordered_map<int, vector<int>> dup;
        for(int i = 0; i<n; i++){
            dup[arr[i]].push_back(i);
        }
        

        int minJumps = 0;

        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;

        
        while(!q.empty()){
            int sz = q.size();

            while(sz-- > 0){
                int i = q.front(); q.pop();

                if(i == n-1)
                    return minJumps;

                if(i - 1 >= 0 && !vis[i - 1]){
                    q.push(i - 1);
                    vis[i-1] = true;
                }

                if(i + 1 < n && !vis[i + 1]){
                    q.push(i + 1);
                    vis[i + 1] = true;
                }

                for(int &nei: dup[arr[i]]){
                    if(!vis[nei] && nei != i){
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
                dup[arr[i]].clear();
            }
            minJumps++;

        }

        

        return 0;
        

    }
};