class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        left, right = 0, len(nums) - 1
        
        while (left <= right): # natural loop exiting condition
            mid = (left + right)//2 # finding out mid
            if(nums[mid] == target): # solution condition
                return mid
            elif (target < nums[mid]): # Array is sorted. so if this condition satisfies then target will always be at the left side.
                right = mid-1 # We just need to check upto the previous element before mid
            elif (nums[mid] < target):
                left = mid + 1 # Same with this, just next element
        return left # If the target isnt found then after the left it should be inserted
    
    # eta na bujhte parle coding cherede