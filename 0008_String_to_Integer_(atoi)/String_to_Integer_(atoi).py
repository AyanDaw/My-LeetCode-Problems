class Solution:
    def myAtoi(self, s: str) -> int:
        # 'caret' acts like a pointer or index.
        # It tells us which character we are currently reading in the string.
        caret = 0

        # 'n' stores the total length of the input string.
        # This helps us avoid going out of bounds.
        n = len(s)

        # STEP 1: Ignore leading spaces
        # As long as:
        # 1. We are still inside the string (caret < n)
        # 2. The current character is a space
        # we keep moving forward.
        while (caret < n and s[caret] == ' '):
            caret += 1

        # STEP 2: Handle sign (+ or -)
        # By default, assume the number is positive.
        sign = 1

        # If the current character is '+' or '-'
        if caret < n and (s[caret] == '+' or s[caret]=='-'):

            # If it's '-', the final number should be negative.
            if s[caret] == '-':
                sign = -1

            # Move forward because the sign has been processed.
            caret += 1

        # STEP 3: Convert digits to number
        # 'num' will store the final numeric value.
        num = 0

        # Maximum allowed integer value (32-bit signed)
        INT_MAX = 2**31 - 1

        # Minimum allowed integer value (32-bit signed)
        INT_MIN = -2**31

        # Read characters while they are digits (0–9)
        while caret < n and s[caret].isdigit():

            # Convert character digit ('5') to integer (5)
            # ord('5') - ord('0') = 5
            digit = ord(s[caret]) - ord('0')

            # STEP 4: Overflow check

            # Before multiplying by 10, we check:
            # Would num*10 + digit exceed INT_MAX?
            #
            # Rearranged safely to:
            # num > (INT_MAX - digit) // 10
            #
            # If true, overflow will happen.
            if num > (INT_MAX-digit)//10:
                return INT_MAX if sign == 1 else INT_MIN
            
            # Safe to update number
            num = num*10 + digit

            # Move to the next character
            caret += 1

        # STEP 5: Apply sign and return
        return num * sign
