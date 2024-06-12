class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int i = 0, j = 0;

        while(j < m){
            nums1.push_back(nums2[j++]);
        }

        sort(nums1.begin(), nums1.end());

        n = nums1.size();
        if(n % 2){
            double mid = nums1[n/2] / 1.0;
            return mid;
        }else{
            double mid = (nums1[n/2] + nums1[n/2-1]) / 2.0;
            return mid / 1.0;
        }
    }
};