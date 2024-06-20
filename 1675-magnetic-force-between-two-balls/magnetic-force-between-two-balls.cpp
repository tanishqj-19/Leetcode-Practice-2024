class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int low  = 1 , high = 0;
        int n = position.size();

        sort(position.begin(), position.end());

        high = position[n-1] - position[0];

        while(low <= high){
            int mid = (low + high)/ 2;

            int d = 1, prev = position[0];
            for(int i = 1; i<n; i++){
            
                if(position[i] - prev >= mid){
                    d++;
                    prev = position[i];
                }
            }

            if(d >= m){
                low  = mid + 1;
            }else
                high = mid-1;
                
        }


        return high;



        
    }
};