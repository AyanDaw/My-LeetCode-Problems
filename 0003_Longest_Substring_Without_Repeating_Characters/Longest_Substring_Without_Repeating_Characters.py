class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        r = 0
        l = 0
        maxlen = 0
        dc = {}
        for r, ch in enumerate(s):
            if ch in dc.keys():
                if l <= dc[ch]:         
                    l = dc[ch] + 1
                    dc[ch] = r
                else:
                    dc[ch] = r

            else:
                dc[ch] = r
            rllength = r - l + 1
            maxlen = max(rllength, maxlen)

        return maxlen