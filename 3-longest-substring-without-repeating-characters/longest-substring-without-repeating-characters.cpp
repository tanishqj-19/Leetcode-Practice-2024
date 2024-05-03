class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> track;

        int  i =0;

        int maxi = 0;

        for(int j = 0; j<s.size(); j++){
            
            if(track.find(s[j]) != track.end()){
                i = max(i, track[s[j]] + 1);
            }

            maxi = max(maxi, j - i + 1);
            track[s[j]] = j;
        }


        return maxi;
    }
};