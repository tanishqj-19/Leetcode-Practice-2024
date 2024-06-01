class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int sum  = 0;
        for(int i = 0; i<n; i++){
            int freq[26] = {0};
            for(int j = i; j<n; j++){
                freq[s[j] - 'a']++;
                if(j == i)
                    continue;

                int maxF = 0, minF = n;

                for(int k = 0; k<26; k++){
                    if(freq[k] > 0){
                        maxF = max(freq[k], maxF);
                        minF = min(freq[k], minF);
                    }
                }
                sum += (maxF-minF);
            }
        }

        return sum;
    }
};