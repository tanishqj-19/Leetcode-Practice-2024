class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0, high = n-1;

        int h = 0;

        while(low <= high){
            int mid = (low + high) >> 1;

            if(citations[mid] == n - mid){
                return n-mid;
            }else if(citations[mid] > n - mid){
                high = mid-1;
            }else
                low = mid + 1;
        }

        return n-low;
    }
};