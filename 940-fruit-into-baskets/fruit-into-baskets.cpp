class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0;

        unordered_map<int, int> freq;
        int maxlen = 0;
        for(; r < n; r++){
            freq[fruits[r]]++;

            while(freq.size() > 2){
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};