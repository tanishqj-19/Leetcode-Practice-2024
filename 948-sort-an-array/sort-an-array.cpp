class Solution {

    void merged(vector<int> &nums, int l,int mid, int r){

        int left = l, right = mid + 1, k = 0;

        vector<int> sorted(r - l + 1);

        while(left <= mid && right <= r){
            if(nums[left] >= nums[right]){
                sorted[k] = nums[right]; k++;
                right++;
            }else{
                sorted[k++] = nums[left];
                left++;
            }
        }

        while(left <= mid){
            sorted[k++] = nums[left++];
        }
        while(right <= r){
            sorted[k++] = nums[right++]; 
        }

        for(int i = 0; i<sorted.size(); i++){
            nums[i + l] = sorted[i];
        }
            
    }
    void mergeSort(vector<int> &nums, int start, int end){
        if(start >= end)
            return;
        
        int mid = (start + end)/2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merged(nums, start, mid, end);
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};