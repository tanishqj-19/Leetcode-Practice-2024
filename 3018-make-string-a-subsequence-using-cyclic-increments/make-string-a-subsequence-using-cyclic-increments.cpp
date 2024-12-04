class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int move = 0, i = 0, j = 0;
        int n1 = str1.size(), n2 = str2.size();

        if(n2 > n1)
            return false;
        while(i < n1 && j < n2){
            if(str1[i] == str2[j] || (str1[i] != 'z' && char(str1[i] + 1) == str2[j])){
                i++;j++;
            }else if(str1[i] == 'z' && 'a' == str2[j]){
                
                i++; j++;
            }else{
                i++;
            }
            
        }
        
        return j >= n2;
    }
};