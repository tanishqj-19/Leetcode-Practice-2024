class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res  = "";

        int n = a + b, ca = 0, cb = 0;

        for(int i = 0; i<n; i++){
            if( (a >= b && ca < 2) || (a > 0 && cb == 2)){
                a--;
                res += 'a';
                ca++;
                cb = 0;
            }else{
                b--;
                res += 'b';
                cb++;
                ca = 0;
            }
        }

        return res;
    }
};