class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());
        int Finalsum = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size()-2; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int front = i+1, back = nums.size() - 1;

            while(front < back){
                int sum = nums[i] + nums[front] + nums[back];
                
                if(sum == target )
                    return sum;
                else if (abs(target - sum) < abs(target-Finalsum))
                    Finalsum = sum;
                
                if (sum > target)
                    back--;
                else 
                    front++;
            }
        }
        return Finalsum;
        
    }
};