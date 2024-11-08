public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int n = nums.Length;
        int[] prefix_xor = new int[n];

        prefix_xor[0] = nums[0];
        int[] res = new int[n];

        int maxVal = (1 << maximumBit) - 1;

        for(int i = 1; i<n; i++){
            prefix_xor[i] = nums[i] ^ prefix_xor[i-1];
        }

        for(int i = 0; i <n; i++){
            res[i] = prefix_xor[n-i-1] ^ maxVal;
        }

        return res;
    }
}