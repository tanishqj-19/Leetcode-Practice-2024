class Solution {
public:
    int getLucky(string s, int k) {
        
        string sum = "";
        for(char &c: s){
            int x = (c - 'a') + 1;
            sum += to_string(x);
        }
        

    
        int curr = 0;
        while(k--){

            curr = 0;

            for(char& c: sum){
                curr += (c - '0');
            }
            sum = "";
            sum += to_string(curr);

        
            
        }

        return curr;


    }
};