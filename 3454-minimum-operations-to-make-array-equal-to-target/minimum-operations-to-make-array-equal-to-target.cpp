#define ll long long

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();

        for(int i = 0; i<n; i++){
            nums[i] = target[i] - nums[i];
        }
        ll minOps = 0;
        int prev = 0;

        for(int i = 0; i<n; i++){
            
            if(nums[i] >= 0){
                if (nums[i] > prev){
                    minOps += (nums[i] - max(prev, 0));
                }
            }else{
                if(nums[i] < prev){
                    minOps += -(nums[i] - min(prev, 0));
                }
            }
            prev= nums[i];
        }

        

        return minOps;
    }
};