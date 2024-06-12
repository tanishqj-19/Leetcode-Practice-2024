class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , mid = 0, j = n-1;
        if(n == 1)
            return;

        while(mid <= j){
            if(nums[mid] == 0){
                swap(nums[mid], nums[i]);
                i++;  mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[j]);
                j--;

            }else{
                 mid++;
            }
           
        }
    }
};