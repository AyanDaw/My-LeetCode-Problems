class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums) 
        prev = nums[0]
        i = 1
        k = 1
        for i in nums[1:]:
            
            if prev != i:
                prev = i
                nums[k] = i
                k += 1
                
        return k