public class Solution {
    private bool[] isPrime;
    private void PrimeNumber(){
        isPrime = new bool[1001];
        
        for(int i = 0; i<=1000; i++) isPrime[i] = true;

        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i<=Math.Sqrt(1000); i++){
            if(isPrime[i]){
                for(int j = i * i; j <=1000; j += i)
                    isPrime[j] = false;
            }
        }
    
    }
    public bool PrimeSubOperation(int[] nums) {

        PrimeNumber();
        int n = nums.Length;

        int prev = -1;
        for(int i = 0; i<n; i++){
            int curr = nums[i];
            for(int j = nums[i]-1; j >= 2; j--){
                if(isPrime[j] && (nums[i] - j) > prev){
                    Console.Write(j + " ");
                    curr = nums[i] - j;

                    break;
                }
            }
            if(prev >= curr)
                return false;
            prev = curr;
        }
        return true;
    }
}