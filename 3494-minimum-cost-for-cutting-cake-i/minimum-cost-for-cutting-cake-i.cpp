#define ll long long
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hcut, vector<int>& vcut) {
        sort(hcut.begin(), hcut.end());
        sort(vcut.begin(), vcut.end());
        ll cost = 0;
        
        
        int hi = 0, vi = 0;
        ll mh = 1, mv = 1;

        while(vcut.size() || hcut.size()){
            ll vv = -1, hv = -1;

            if(!vcut.empty()){
                vv = vcut.back();
            }

            if(!hcut.empty()){
                hv = hcut.back();
            }

            if(hv >= vv){
                cost += (hv * mv);
                mh++;
                hcut.pop_back();
            }else{
                cost += (vv * mh);
                vcut.pop_back();

                mv++;
                
            }
        }

        return cost;

    }
};