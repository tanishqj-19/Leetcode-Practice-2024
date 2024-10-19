class Solution {

    string invertReversed(string s){
        for(char &c: s){
            if(c == '0'){
                c = '1';
            }else{
                c = '0';
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    char findKthBit(int n, int k) {
        
        vector<string> dp(n + 1);

        dp[1] = "0"; 

        if(n == 1){
            return dp[1][k-1]; 
        }
        dp[2] = "011";
        if(n == 2)
            return  dp[2][k-1];

        for(int i = 3; i<= n; i++){
            string temp = invertReversed(dp[i-1]);
            dp[i] = (dp[i-1] + "1" + temp);
        }
    

        return dp[n][k-1];
        
    }
};