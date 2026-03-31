class Solution:
    def shift(self, nums: List[int], id: int, size2: int, count: int) -> None:
        i=len(nums)-size2+count
        while i>=id:
            nums[i]=nums[i-1]
            i-=1;
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=0
        j=0
        while i<m+j and j<n:
            if nums2[j]<nums1[i]:
                self.shift(nums1, i, n, j)
                nums1[i]=nums2[j]
                j+=1
            i+=1
        while j<n:
            nums1[i]=nums2[j]
            j+=1
            i+=1