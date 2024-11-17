

public class Solution {
    public int ShortestSubarray(int[] nums, int k) {
        int n = nums.Length;
        var pq = new SortedSet<(long Sum, int Index)>();
        long sum = 0;
        int minlen = n + 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k) {
                minlen = Math.Min(minlen, i + 1);
            }
            while (pq.Count > 0 && sum - pq.Min.Sum >= k) {
                minlen = Math.Min(minlen, i - pq.Min.Index);
                pq.Remove(pq.Min);
            }
            pq.Add((sum, i));
        }

        return minlen > n ? -1 : minlen;
    }
}
