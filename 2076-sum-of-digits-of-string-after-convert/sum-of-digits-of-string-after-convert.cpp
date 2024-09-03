class Solution {
public:
    int getLucky(string s, int k) {
        
        int curr = 0;

        for(char &c: s){
            int x = (c - 'a') + 1;
            if(x < 10){
                curr += x;
            }else{
                curr += (x % 10 + x / 10);
            }
        }
        
        k-= 1;
    
        while(k-- && curr >= 10){
            curr = sum(curr);
            
        }

        return curr;


    }

    int sum(int x){
        int val = 0;

        while(x){
            val += x % 10;
            x /= 10;
        }

        return val;
    }
};