# Check the C++ file for explaining comments, i cant understand what is happening in this code. I took help from AI
# TODO: Solve this problem again. Without the help of AI. 

class Solution:
    def f(self, i, j, p, s, dp):
        if (i < 0 and j < 0): return True
        if (i < 0 and j >= 0): return False

        if (i >= 0 and j < 0):
            while (i >= 0):
                if (p[i] != '*'): return False
                i -= 2
            return True

        if (dp[i][j] != -1): return dp[i][j]

        if (p[i] == s[j] or p[i] == '.'):
            dp[i][j] = self.f(i-1, j-1, p, s, dp)
            return dp[i][j]

        if (p[i] == '*'):
            zero = False
            if (i - 2 >= -1):
                zero = self.f(i - 2, j, p, s, dp)

            oneOrMore = False
            if (i - 1 >= 0 and j >= 0 and (p[i-1] == s[j] or p[i-1] == '.')):
                oneOrMore = self.f(i, j - 1, p, s, dp)

            dp[i][j] = zero or oneOrMore
            return dp[i][j]

        dp[i][j] = False
        return dp[i][j]

    def isMatch(self, s: str, p: str) -> bool:
        n = len(p)
        m = len(s)
        if (n == 0 and m == 0): return True
        if (n == 0): return False

        dp = [[-1]*m for _ in range(n)]
        return self.f(n - 1, m - 1, p, s, dp)
