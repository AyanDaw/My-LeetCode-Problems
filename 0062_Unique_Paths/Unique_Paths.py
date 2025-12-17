class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Example 1: There are 7 cells in horizontal and 3 vertical. In total i need to move maximum 6 left and maximum 2 downs
        # Exact 6 + 2 = 8 moves
        # Lets imagine this as an array of 8 slots where i have 2 options, right or left
        # And thats nCr, 8C2
        total = m-1 + n-1
        # possible combinations are (m + n - 2)C(m - 1)   or   (m + n - 2)C(n - 1)
        return math.comb(total, m-1)