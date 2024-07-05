class Solution {
    int n;
    vector<long long> dp;
    long long solve(int i, vector<int> &nums1, vector<int> &nums2, int last1, int last2){
        if(i >= n)
            return 0;
        
        

        if(i > 0 && (last1 >= nums1[i] || last2 >= nums2[i])){
            int val = 1 + solve(i + 1, nums1, nums2, nums2[i], 
                nums1[i]);
                return val;
        }
        else if (i > 0 &&(last1 >= nums2[i] || last2 >= nums1[i])){
            return  solve(i + 1, nums1, nums2, nums1[i], nums2[i]);
        }
        else{
            if(dp[i] != -1)
                return dp[i];
            long long one =  solve(i + 1, nums1, nums2, nums1[i], nums2[i]);

            long long two = 1 + solve(i + 1, nums1,nums2, nums2[i], nums1[i]);

            return dp[i] = min(one,two);
        }
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
     
        dp.resize(n, -1);
        return  solve(0,  nums1, nums2, nums1[0], nums2[0]);
    }
};