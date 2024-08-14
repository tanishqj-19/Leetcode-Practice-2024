class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0, right = nums[n-1]  - nums[0];

        while(left < right){
            int mid = left + (right - left) / 2;
            int i = 0, j = 0, count = 0;


            for(; i<n; i++){
                while(j < n && nums[j] - nums[i] <= mid)
                    j++;
                count += (j - i - 1);
            }

            if(count >= k)
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};