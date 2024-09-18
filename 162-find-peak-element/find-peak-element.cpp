class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size(), i = 1, j = n-2;

        if(n == 1)
            return 0;
        if(arr[0] > arr[1])
            return 0;
        if(arr[n-1] > arr[n-2])
            return n-1;

        while(i <= j){
            int mid = (i + j) / 2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid + 1])
                return mid;
            if(arr[mid] > arr[mid-1])
                i = mid+1;
            else
                j = mid - 1;
        }

        return -1;
    }
};