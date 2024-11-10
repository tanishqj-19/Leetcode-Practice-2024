public class Solution {
    private void updateBit(int[] bitCount, int number, int val) {
        for (int i = 0; i < 32; i++) {
            if ((number & (1 << i)) != 0)
                bitCount[i] += val;
        }
    }

    private int ConvertBit(int[] bitCount) {
        int number = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCount[i] != 0) {
                number |= 1 << i;
            }
        }
        return number;
    }

    private bool ValidSubarray(int[] nums, int k, int currWindow) {
        int[] bitCount = new int[32];

        for (int i = 0; i < nums.Length; i++) {
            updateBit(bitCount, nums[i], 1);

            if (i >= currWindow) {
                updateBit(bitCount, nums[i - currWindow], -1);
            }

            if (i >= currWindow-1 && ConvertBit(bitCount) >= k)
                return true;
        }

        return false;
    }

    public int MinimumSubarrayLength(int[] nums, int k) {
        int left = 1, right = nums.Length;
        int minlen = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool isValid = ValidSubarray(nums, k, mid);

            if (isValid) {
                minlen = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minlen;
    }
}
