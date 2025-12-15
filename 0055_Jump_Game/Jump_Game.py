class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        maxrange = 0
       # maxrange keeps track of the farthest index reachable so far

        for i in range(n):
        # If the current index is greater than the farthest reachable index,
        # then this position is unreachable by any previous jump
            if i > maxrange:
                return False

            # Update the farthest reachable index using the current position
            maxrange = max(maxrange, i + nums[i])
            # i + nums[i] represents how far we could reach if we ever land on index i

        # If we never encounter an unreachable index,
        # the last index is reachable
        return True
