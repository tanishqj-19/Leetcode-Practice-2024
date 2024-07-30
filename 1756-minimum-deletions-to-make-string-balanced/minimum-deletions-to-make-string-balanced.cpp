class Solution {
    int n;
public:
    int minimumDeletions(string s) {
        n = s.size();

        int b = 0; 
        int moves = 0;

        for(int i = 1; i<=n; i++){
            if(s[i-1] == 'a'){
                moves = min(b, moves + 1);
            }else{
                b++; 
            }
        }


        return moves;
        
    }
};