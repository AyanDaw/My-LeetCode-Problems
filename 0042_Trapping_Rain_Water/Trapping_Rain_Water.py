# Check the Cpp file for explaining comments

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        lmax, rmax, total, l, r = 0, 0, 0, 0, n-1

        while l < r:
            if height[l] <= height[r]:
                if lmax > height[l]:
                    total += lmax - height[l]
                else:
                    lmax = height[l]
                l += 1
            else:
                if rmax > height[r]:
                    total += rmax - height[r]
                else:
                    rmax = height[r]
                r -= 1
        
        return total