class Solution(object):
    def intersect(self, nums1, nums2):
        if len(nums1) > len(nums2):
            self.intersect(nums2, nums1)
        
        dic = Counter(nums1)
        l = []
        
        for i in nums2:
            if dic[i] > 0:
                dic[i] -= 1
                l.append(i)
        return l

        