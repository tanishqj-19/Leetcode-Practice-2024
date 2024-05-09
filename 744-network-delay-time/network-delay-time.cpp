class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, 1e9);

        dis[k] = 0;

        for(int  i = 1; i<=n; i++){
            for(int j = 0; j<times.size(); j++){
                int  src = times[j][0], des = times[j][1], w = times[j][2];
                
                if(dis[src] != 1e9 && dis[des] > dis[src] + w){
                    dis[des] = dis[src] + w;
                }
            }
        }


        int mytime = 0;

        for(int i = 1; i<=n; i++){
            
                mytime = max(mytime, dis[i]);
        }

        if(mytime >= 1e9)
            return -1;
        return mytime;
    }
};