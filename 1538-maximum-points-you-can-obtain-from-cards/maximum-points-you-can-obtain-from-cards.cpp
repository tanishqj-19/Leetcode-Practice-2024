class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), i = 0, 
        leftsum = 0, rightsum = 0;

        for(; i < k; i++) leftsum += cardPoints[i];
    
        int j = n-1, maxsum = leftsum;
        i = k-1;
        while(i >= 0){
            leftsum -= cardPoints[i--];
            rightsum += cardPoints[j--];
            maxsum = max(maxsum, leftsum + rightsum);
        }

        return maxsum;

    }
};