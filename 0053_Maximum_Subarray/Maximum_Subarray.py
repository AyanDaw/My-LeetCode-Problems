# Check the cpp file for the explaining comments

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currsum, maxsum = nums[0], nums[0]
        for i in nums[1:]:
            currsum = max(i, currsum + i)
            maxsum = max(maxsum, currsum)
        return maxsum