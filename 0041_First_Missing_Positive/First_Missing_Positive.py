class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)       # Getting length of List
        i = 0               # Counter

        while i < n:
            correctindex = nums[i] - 1      # Unlike C++, Pyhton is not that much intelligent to calculate inside the List 3rd brackets
            if 0 < nums[i] < n+1 and nums[i] != nums[correctindex]:
                nums[i], nums[correctindex] = nums[correctindex] , nums[i]      # Swap
            else:
                i += 1      # Increment
            
        for i in range(n):
            if nums[i] != i+1:      # At which element we could not find the next index same that one is the missing
                return i + 1        # Returning 
        
        return n + 1        # If 1...n all are available then n+1 is the missing one