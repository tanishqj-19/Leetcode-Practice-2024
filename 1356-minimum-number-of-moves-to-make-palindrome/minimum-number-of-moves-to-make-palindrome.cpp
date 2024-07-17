class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int  moves = 0;

        while(!s.empty()){
            int k = s.find(s.back());

            if(k == s.size() - 1){
                moves += k/2;
            }else{
                moves += k;
                s.erase(k, 1);

            }
            s.pop_back();
        }
        

    
        return moves;




    }
};