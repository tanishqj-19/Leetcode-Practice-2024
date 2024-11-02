class Solution {
public:
    bool isCircularSentence(string s) {
        
        if(s[0] != s[s.length()-1])
            return false;
        for(int i=1; i<s.size(); i++){
            
            char prev = s[i-1];
            if(s[i] == ' '){
                if(s[i+1] != prev) return false;
            }
        }
        
        
        return true;
            
    }
};