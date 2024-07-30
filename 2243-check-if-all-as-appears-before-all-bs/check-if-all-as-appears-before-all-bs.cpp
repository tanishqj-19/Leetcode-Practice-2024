class Solution {
public:
    bool checkString(string s) {
        int b = 0;

        for(char &c: s){
            if(c == 'b')
                b++;
            if(c == 'a' && b > 0)
                return false;
        }
        return true;
    }
};