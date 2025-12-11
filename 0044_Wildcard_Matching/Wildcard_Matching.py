# Check C++ file for explaining comments

class Solution:
    def f(self, dp, i, j, p, s):
        # Base cases
        if(i<0 and j<0): return True
        if(i<0 and j>=0): return False
        if(i>=0 and j<0):
            for ii in range(i, -1, -1):
                if(p[ii] != '*'): return False
            return True

        if (dp[i][j] is not None): return dp[i][j]

        # direct match or '?'
        if (p[i] == s[j] or p[i] == '?'):
            dp[i][j] = self.f(dp, i-1, j-1, p, s)
            return dp[i][j]

        if(p[i] == '*'):
            dp[i][j] = self.f(dp, i-1, j, p, s) or self.f(dp, i, j-1, p, s)
            return dp[i][j]
        
        dp[i][j] = False
        return dp[i][j]


    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        if(m == 0 and n == 0): return True 
        # Dutoi faka.
        
        if(n==0): return False 
        # Text ache but pattern e kichu nei
        
        dp = [[None]*m for _ in range(n)] 
        # Similar to 2D array. Every room is initialized with -1.

        return self.f(dp, n-1, m-1, p, s)