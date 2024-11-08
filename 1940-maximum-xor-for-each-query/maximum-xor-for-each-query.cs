public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int n = nums.Length;
        int xor = 0;
        int[] res = new int[n];

        int maxVal = (1 << maximumBit) - 1;
        foreach(int num in nums){
            xor ^= num;
        }
        
        

        for(int i = 0; i <n; i++){
            res[i] = xor ^ maxVal;
            xor ^= nums[n-i-1];
        }

        return res;
    }
}