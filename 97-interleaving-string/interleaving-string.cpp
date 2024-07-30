class Solution {

   int n1,n2,n3;
   int dp[101][101][201];
public:
    bool isInterleave(string s1, string s2, string s3) {
        n3 = s3.size(), n2 = s2.size(), n1 = s1.size();

        if(n2 + n1 != n3)
            return false;
        
        if(n1 == 0 && n2 == 0 && n3 == 0)
            return true;
        memset(dp, -1,  sizeof(dp));

        return f(s1, s2, s3, 0, 0, 0);
    }

    bool f(string &s1, string &s2, string &s3, int i,int j,int k){
        if(i >= n1 && j >= n2 && k >= n3)
            return true;
        if(s1[i] != s3[k] && s3[k] != s2[j])
            return false;
        if(i >= n1){
            if(s2[j] != s3[k])
                return false;
        }

        if(j >= n2){
            if(s1[i] != s3[k])
                return false;
        }

        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        bool sol = false;
        if(s1[i] == s3[k]){
            sol |= f(s1, s2, s3, i + 1, j, k + 1);
        }

        if(s2[j] == s3[k])
            sol |= f(s1, s2, s3, i, j + 1, k + 1);
        return dp[i][j][k] =  sol;
    }
};