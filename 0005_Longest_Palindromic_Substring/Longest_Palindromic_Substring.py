# check C++ file for explaining comments

class Solution:
    def checkPalinLen(self, s, left, right):
        n = len(s)
        while(left >= 0 and right < n and s[left]==s[right]):
            left-= 1
            right+= 1
        
        return right - left - 1
    
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        if n < 2: return s
        start, maxLen = 0, 0
        for i in range(0, n):
            len1 = self.checkPalinLen(s, i, i)
            len2 = self.checkPalinLen(s, i, i+1)
            Len = max(len1, len2)
            if (maxLen < Len):
                maxLen = Len
                start = i - (Len-1)//2
        
        return s[start: start + maxLen]