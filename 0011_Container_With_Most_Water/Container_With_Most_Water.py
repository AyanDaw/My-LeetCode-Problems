# Check the cpp file for explanation comments
class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        lp = 0
        rp = n-1
        mostvol = 0

        while(lp < rp):
            w = rp - lp
            h = min(height[lp],height[rp])
            vol = w*h

            if mostvol<vol:
                mostvol = vol
            if height[lp]<height[rp]:
                lp +=1  
            else:
                rp -= 1

        return mostvol