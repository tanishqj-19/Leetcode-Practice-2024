class Solution {

    bool partition(vector<int> &nums, vector<int> &visited, int idx, int k, int target,
            int currSum){
        if(k == 1){
            return true;
        }
        if(currSum > target)
            return false;

        if(currSum == target)
            return partition(nums, visited, 0, k-1, target, 0);

        for(int i = idx; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                if(partition(nums, visited, i+1, k, target, currSum + nums[i]))
                    return true;
                visited[i] = 0;
            }
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        if(k <= 0 || sum % k != 0)
            return false;

        int sub_sum = sum / k;
        vector<int> visited(n, 0);

        return partition(nums, visited, 0, k, sub_sum, 0);

    }
};