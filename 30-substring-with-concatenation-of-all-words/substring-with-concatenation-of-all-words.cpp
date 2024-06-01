class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), wordArrSize = words.size();

        unordered_map<string, int> cnt;
        vector<int> out;

        for(string& w: words) cnt[w]++;

        int wordSize = words[0].size();

        for(int i = 0; i<wordSize; i++){
            unordered_map<string , int> seen;
            int wc = 0;
            int left = i;


            for(int j = i; j<=n-wordSize; j+= wordSize){
                string subWord = s.substr(j, wordSize);

                if(cnt.count(subWord)){
                    seen[subWord]++;
                    if(seen[subWord] <= cnt[subWord]){
                        wc++;
                    }else{
                        while(cnt[subWord] < seen[subWord]){
                            string temp = s.substr(left, wordSize);
                            seen[temp]--;
                            if(cnt[temp] > seen[temp]){
                                wc--; 
                            }
                            left += wordSize;
                        }
                    }

                    if(wc == wordArrSize){
                        out.push_back(left);
                        seen[s.substr(left, wordSize)]--;
                        left += wordSize;
                        wc--;
                    }
                }else{
                    wc = 0;
                    seen.clear();
                    left = j +  wordSize;
                }
            }

            
        }
        

        return out;

    }
};