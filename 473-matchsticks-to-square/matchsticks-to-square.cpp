#define ll long long

class Solution {
    vector<bool> vis;

    int tar;

    bool subsetSum(vector<int> &arr, int idx, int k, ll sum){
        if(k == 1)
            return true;
        if(sum > tar)
            return false;
        if(sum == tar){
            
            return subsetSum(arr, 0, k-1, 0);
        }
        
        for(int i = idx; i <arr.size(); i++){
            if(!vis[i] && sum + (ll) arr[i] <= tar){
                vis[i] = true;
                if(subsetSum(arr, i + 1, k, sum + arr[i]))
                    return true;
                vis[i] = false;


            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        ll sum = accumulate(matchsticks.begin(), matchsticks.end(), 0); 

        if(n < 4 || sum % 4)
            return false;
        int k = sum / 4;
        tar = k;
        vis.resize(n, false);
    
        return subsetSum(matchsticks, 0, 4, 0);

    




    }
};