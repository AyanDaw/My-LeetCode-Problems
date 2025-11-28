class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -2**31 # Defining the lower limit
        INT_MAX = (2**31) - 1 # Defining the upper limit
        # I dont know if there is any long long type like type in Python but i do knew python's int can expand as much as needed so for now I have done it using int for temporalily. but i do make sure Condition check is still there. 
        r = 0
        sign = -1 if x<0 else 1 # Preserving the Sign
        x = abs(x) # Unlike C++, Python have problems with negative numbers. so we turned x into its mod (|x|) value or absolute value

        while x != 0:
            r = (r * 10) + (x % 10)
            x = x // 10     # same reversing algorithm 
        
        r = r*sign # Returning r its sign
        if (INT_MIN <= r <= INT_MAX):    # there no need to gum two conditions with 'and' like in C++.
            return r
        else:
            return 0 # as we are asked in the question.