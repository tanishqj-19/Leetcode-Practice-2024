public class Solution {
    public int FindLengthOfShortestSubarray(int[] arr) {
        int n = arr.Length;
        
        int end = n-1;

        while(end > 0 && arr[end] >= arr[end - 1]) end--;
        // Console.WriteLine(end);
        if(end == 0)
            return 0;

        int start = 0;
        int shortest = end;

        while(start < end && (start == 0 || arr[start - 1] <= arr[start])){

            while(end < n && arr[start] > arr[end]){
                end++;
            }
            shortest = Math.Min(end - start - 1, shortest);
            start++;
        }

       
        return shortest;
    }
}