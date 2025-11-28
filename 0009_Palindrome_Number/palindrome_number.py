class Solution:
    def isPalindrome(self, x: int) -> bool:     # We will check half of the digits of the numbers to avoid overflow of signed int variable
        if x < 0 or (x % 10 == 0 and x != 0):   # Eliminating the negatives as they will be -121 ≠ 121-. Also eliminating products of 10, as they will never be palindrome, 100 ≠ 001. 10 will also create a logical error, in this will get eliminated too.
            return False
        r = 0                                   # Initialize the dumping variable as 0
        while x > r:                            # As the it crosses the half of the digits, the loop get stopped. Giving Either x ≠ r, or x = r (when even digits), or x < r (when odd digits)
            r = r * 10 + x % 10                 # Takes one digit from last of 'x', shifts the 'r' towards left by one decimal. adds the last digit at last. which will eventually get shifted to front.
            x = x // 10                         # Removing one digit one by one from the end.
        return x == r or x == r // 10           # if it was palindrome and even it will surely give you x == r (ex. 1221, 12 == 12), and if odd it will give x < r, (ex. 121, 1 < 12), so we remove the last digit from 'r'. this creates a loop hole for 10. so we eliminate it at the beginning.