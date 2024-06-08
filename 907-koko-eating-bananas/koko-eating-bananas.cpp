class Solution {

    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1e9;
    
        while(low <= high){
            int midEat = (low + high)/ 2;
            long long total = 0;

            for(int pile: piles) total += ((pile + midEat -1) / midEat);

            if(total > h){
               low = midEat + 1;
            }else{
                high = midEat-1;
            }
                
        }

        return low;
    }
};