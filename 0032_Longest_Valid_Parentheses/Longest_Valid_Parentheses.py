class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]     # base index for calculating lengths
        maxlen = 0

        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            else:  # ch == ')'
                # pop the matching '(' index (if any)
                stack.pop()
                if not stack:
                    # no unmatched '(' to anchor a valid substring -> set new base
                    stack.append(i)
                else:
                    # length of current valid substring ending at i
                    maxlen = max(maxlen, i - stack[-1])

        return maxlen
