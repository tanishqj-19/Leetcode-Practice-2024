class Solution {
    public String longestDiverseString(int a, int b, int c) {
        String ans = "";

        int currA = 0, currB = 0, currC = 0;
        int n = a + b + c;
        for(int i = 0; i<n; i++){

            if( (a > 0 && currB == 2) || (a > 0 && currC == 2) || 
                (a >= b && a >= c && currA < 2)){
                
                currA++;
                ans += 'a';
                a--;
                currC = currB = 0;
            }else if( (b > 0 && currA == 2) || (b > 0 && currC == 2) || (b >= a && b >= c && currB < 2)){
                currB++;
                ans += 'b';
                b--;
                currA = currC = 0;
            }else if((c > 0 && currB == 2) || (c > 0 && currA == 2) || (c >= a && c >= b && currC < 2)){
                currC++;
                ans += 'c';
                c--;
                currA = currB = 0;
            }else{
                break;
            }
        }

        return ans;
    }
}