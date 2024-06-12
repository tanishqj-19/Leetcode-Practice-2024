class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int i = 0, j = 0;

       int m1 = 0 ,m2= 0;
       
        int size = n + m;
        
        for(int c = 0; c <= size/2; c++){
            m2 = m1;
            if(i < n && j < m){
                if(nums1[i] < nums2[j]){
                    m1 = nums1[i];
                    i++;
                }else{
                    m1 = nums2[j++];
                }
            }else if(i < n){
                m1 = nums1[i];
                    i++;
            }else if(j < m)
                 m1 = nums2[j++];
                
        }
        
        if(size % 2){
            return m1/1.0;
        }else
            return (double) (m1 + m2) / 2.0;

  
        
    }
};