public class Solution {

    private long binarySearch(int[] nums,int l, int r, int k){
        
        while( l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] < k){
                l = mid + 1;
            }else{
                r = mid-1;
            }
        }

        return l;
    }
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        int n = nums.Length;
        long cnt=0;
        for(int i = 0; i<n; i++){

            long lowerLimit = binarySearch(nums, i + 1, n-1,  lower - nums[i]);
            long upperLimit = binarySearch(nums, i + 1, n-1, upper + 1 -nums[i]);

            cnt += Math.Abs(lowerLimit - upperLimit);

        }

        return cnt;
    }
}