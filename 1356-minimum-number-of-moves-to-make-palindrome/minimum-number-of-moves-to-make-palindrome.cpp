class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int n = s.size();

        

        int i = 0, j = n-1, center = -1;
        
        int moves = 0;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                int k = i + 1;

                while(k < j){
                    if(s[j] == s[k]){
                        break;
                    }
                    k++;
                }
                if(k == j){
                    center = j;
                    j--;
                    continue;
                }
                for(int t = k; t > i; t--){
                    swap(s[t], s[t-1]);
                    moves++;
                }
                i++;
                j--;
            }
        }

        if(center != -1){
            moves += (center - n/2);
        }

        return moves;




    }
};