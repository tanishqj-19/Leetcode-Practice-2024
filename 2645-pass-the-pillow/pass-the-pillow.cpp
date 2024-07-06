class Solution {
public:
    int passThePillow(int n, int time) {
        
        int  steps = time / (n-1), k = time % (n-1);
        

        return steps % 2 == 0 ? (1 + k) : (n - k);
    }
};