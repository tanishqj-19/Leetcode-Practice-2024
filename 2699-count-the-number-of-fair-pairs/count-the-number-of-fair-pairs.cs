public class Solution {

    private long helper(int[] nums, int k){
        
        int i = 0, j = nums.Length - 1;
        long count = 0;
        while(i < j){
            int sum = nums[i] + nums[j];

            while(i < j && nums[i] + nums[j] < k){
                count += (j - i);
                i++;

            }

            
            j--;
        }

        return count;
    }
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        
        return helper(nums, upper + 1) - helper(nums, lower);
    }
}