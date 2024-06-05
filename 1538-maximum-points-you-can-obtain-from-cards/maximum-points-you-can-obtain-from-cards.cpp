class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), i = 0, 
        leftsum = 0, rightsum = 0;

        for(; i < k; i++) leftsum += cardPoints[i];
    
        int maxsum = leftsum;
        i = 0;
        while(i < k){
            leftsum -= cardPoints[k - i -1];
            rightsum += cardPoints[n-i-1];
            maxsum = max(maxsum, leftsum + rightsum);
            i++;
        }

        return maxsum;

    }
};