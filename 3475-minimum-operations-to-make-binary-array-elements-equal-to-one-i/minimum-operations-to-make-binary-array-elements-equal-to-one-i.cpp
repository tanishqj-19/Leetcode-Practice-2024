class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 3;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {

            if(nums[j] == 0){
                if(j + k -1 >= n)
                    return -1;
                for(int i = j; i < j + k; i++){
                    nums[i] = !nums[i];
                }
                cnt++;
            }
           
            j++;
        }

        return cnt;
    }
};