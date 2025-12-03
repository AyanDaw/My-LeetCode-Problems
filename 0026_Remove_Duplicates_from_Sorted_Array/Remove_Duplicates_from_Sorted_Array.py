class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        prev = nums[0]  # Taking the first element
        k = 1  # Unique value counter. First one will always be unique so 1
        for i in nums[1:]:  # Taking values from 1 index, not 0.

            if prev != i:  # If value doesnot match with previous element, then it means it's unique
                prev = i  # Updating the previous value variable
                # Inserting the current element after the last unique value
                nums[k] = i
                k += 1  # Increasing counter by 1.

        return k  # Returning the counter value.
