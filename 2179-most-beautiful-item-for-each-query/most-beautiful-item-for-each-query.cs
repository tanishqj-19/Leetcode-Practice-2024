public class Solution {
    private int binarySearch(int[][] items, int k){
        int l = 0, r = items.Length - 1;

        int maxBeauty = 0;

        while(l <= r){
            int mid  = (l + r) / 2;
            if(items[mid][0] > k){
                r = mid - 1;
            }else{
                maxBeauty = Math.Max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
        }

        return maxBeauty;
    }
    public int[] MaximumBeauty(int[][] items, int[] queries) {
        Array.Sort(items, (a, b) => a[0].CompareTo(b[0]));

        int maxBeauty = 0;

        for(int i = 0; i < items.Length; i++){
            maxBeauty = Math.Max(items[i][1], maxBeauty);
            items[i][1] = maxBeauty;
            
        }
        int[] ans = new int[queries.Length];

        for(int i = 0; i<queries.Length; i++){
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;


    }
}