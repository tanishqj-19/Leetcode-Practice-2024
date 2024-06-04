class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, r = 0, n = answerKey.size(), cnt = 0, maxCnt = 0;


        for(; r < n; r++){
            cnt += (answerKey[r] == 'F');

            if(cnt > k){
                cnt -= (answerKey[l] == 'F');
                l++;
            }

            maxCnt = max(maxCnt, r - l + 1);
        }

        l = r = cnt = 0;

        for(; r < n; r++){
            cnt += (answerKey[r] == 'T');

            if(cnt > k){
                cnt -= (answerKey[l] == 'T');
                l++;
            }

            maxCnt = max(maxCnt, r - l + 1);
        }


        return maxCnt;
    }
};