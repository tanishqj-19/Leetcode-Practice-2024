class Solution {
public:
    string losingPlayer(int x, int y) {
        int check = min(x, y/4);
        if(check % 2 == 1)
            return "Alice";
        return "Bob";
    }
};