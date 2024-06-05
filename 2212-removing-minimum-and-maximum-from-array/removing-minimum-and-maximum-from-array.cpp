class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minI = 0, maxI = 0, maxi = -1e9, mini = 1e9;

        for(int i = 0; i<n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                maxI = i;
            }

            if(mini > nums[i]){
                mini = nums[i];
                minI = i;
            }
        }

        int ans = 1e9;

        int left = max(minI, maxI) + 1;
        int right = n - min(minI, maxI) ;
        ans = min(left, right);

        //both from left and right;

        int both = min(minI + 1, n - minI) + min(maxI + 1, n - maxI);

        return min(ans, both);

    }
};