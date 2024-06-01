class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int toggle = 0;
        long long cntStr = 0;


        int states[1024] = {0};
        states[0] = 1;

        for(char &c: word){
            int index = c - 'a';

            toggle ^= (1 << index);
            cntStr += states[toggle];

            for(int i = 0; i<10; i++){
                int look = toggle ^ (1 << i);
                cntStr += states[look];
            }
            states[toggle]++;
        }
        return cntStr;
    }
};