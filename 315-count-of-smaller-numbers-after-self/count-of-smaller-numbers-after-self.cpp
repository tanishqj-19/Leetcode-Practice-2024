class Solution {
    vector<int> countSmall;

    void merge(int left, int mid, int right, vector<pair<int, int>> &arr){
        int i = left, j = mid + 1, k =0;

        vector<pair<int, int>> temp(right-left + 1);
        long long cnt = 0;
        while(i <= mid && j <= right){
            if(arr[i].first > arr[j].first){
                cnt++;
                temp[k++] = arr[j++];
            }else{
                countSmall[arr[i].second] += cnt;
                temp[k++] = arr[i++];
                
            }
        }

        while(i <= mid){
            countSmall[arr[i].second] += cnt;
            temp[k++] = arr[i++];
        }

        while(j <= right)
            temp[k++] = arr[j++];
        for(int l = left; l <= right; l++)
            arr[l] = temp[l - left];
        return;
    }

    void helper(vector<pair<int, int>> & arr, int left, int right){
        
        if(left >= right)
            return;
        int mid = (left + right) / 2;

        helper(arr, left, mid);
        helper(arr, mid + 1, right);

        merge(left, mid, right, arr);

        return;

    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        countSmall.resize(n, 0);

        for(int i = 0 ;i<n; i++){
            arr.push_back({nums[i], i});
        }

        

        helper(arr, 0, n-1);

        return countSmall;


    }
};