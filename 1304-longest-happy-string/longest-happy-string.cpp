class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        int cA = 0, cB = 0, cC = 0;
        int maxlen = a + b + c;

        for(int i = 0; i<maxlen; i++){

            if( (a >= b && a >= c && cA < 2) || (a > 0 && cB == 2)  || (a > 0 && cC == 2)){
                cA++;
                a--;
                ans += 'a';
                cB = cC = 0;
            }else if( (b >= a && b >= c && cB < 2) || (b > 0 && (cC == 2 || cA == 2))){
                cB++;
                b--;
                cA = cC = 0;
                ans += 'b';
            }else if( (c >= a && c >= b && cC < 2) || (c > 0 && (cA == 2 || cB == 2))){
                cC++;
                cA = cB = 0;
                ans += 'c';
                c--;
            }else{
                break;
            }
        }

        return ans;
    }
};