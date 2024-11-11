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

        int currVal = 1, i =0;

        while(i < n){
            int diff = nums[i] - currVal;

            if(diff < 0)
                return false;
            

            if(isPrime[diff] || diff == 0){
                i++;
            }
            currVal++;
        }
        return true;
    }
}