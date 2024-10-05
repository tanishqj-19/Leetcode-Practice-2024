class Solution {
private:
    bool freq(vector<int> &freq1, vector<int> &freq2){
        
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {

        if(s2.size() < s1.size()) return false;
        vector<int> freq1(26, 0), freq2(26, 0);

        for(int i=0; i< s1.size(); i++)
            freq1[s1[i] - 'a']++;

        
        int i  = 0;
        
        

        while(i <  s1.size()){
            
            freq2[s2[i] - 'a']++;
            i++;
        }

        if(freq(freq1, freq2)) return true;

        while(i < s2.length()){
            freq2[s2[i] - 'a']++;
            freq2[s2[i-s1.size()] - 'a']--;
            i++;
            if(freq(freq1, freq2)) return true;
        }

        return false;

    }
};