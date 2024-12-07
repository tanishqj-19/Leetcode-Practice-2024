class Solution {
public:
    bool canAssign(vector<int>& nums, int mid,int value){
        int count=0;
        for(int& ele: nums){
            if(ele>mid){
                count+= ceil((double) (ele-mid)/mid);
            }
            if(count>value){
                return false;
            }
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high= *max_element(nums.begin(),nums.end());
        int result=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(canAssign(nums,mid,maxOperations)){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
};