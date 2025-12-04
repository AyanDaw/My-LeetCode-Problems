class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        pos = 0
        
        for x in nums:
            if (x != val):
                nums[pos] = x
                pos += 1
        # Val bade jesob value asbe segulo ke allocate korbe r next tai ready hoye bose thakbe, val esegele skip kore jabe
        return pos # Oitai abar return kore debe