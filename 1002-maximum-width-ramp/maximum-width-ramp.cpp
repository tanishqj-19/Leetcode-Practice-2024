class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
        int n = nums.size();

        vector<int> last_greater(n);

        last_greater[n-1] =  nums[n-1];

        for(int i = n-2; i>=0; i--){
            last_greater[i] = max(last_greater[i + 1], nums[i]);
        }

        int i = 0, j = 0;

        while(j < n){
            while(i < j && nums[i] > last_greater[j])
                i++;
            maxWidth = max(maxWidth, j - i);
            j++;
        }

        return maxWidth;
    }
};