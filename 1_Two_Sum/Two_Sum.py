class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {} # Dictionary in python instead of Map in C++

        for i, num in enumerate(nums): # For getting the indeces as i and values as num
            need = target - num # For the needed value
            if need in mp: # Checks inside mp dictionary
                return [mp[need], i] # Returns the solution as List of integers
            mp[num] = i # Saves in dictionary
        return [] # If the solution is not found