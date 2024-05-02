class Solution {
public:
    int findMaxK(vector<int>& nums) {
        

        unordered_map<int, bool> mp;

        for(int &i: nums){
            if(i > 0) {
                mp[i] = true;
                
            }
        }

        int maxi = -1;
        for(int &i: nums){
            if(i < 0){
                if(mp[abs(i)]){
                    
                    maxi = max(maxi, abs(i));
                }
                
                    
            }
        }

        return maxi;

    }
};