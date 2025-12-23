class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 -1
        INT_MIN = -2**31
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
            # Why only this condition?
            # INT_MAX / 1 = INT_MAX ok
            # INT_MAX / -1 = INT_MIN -1 ok
            # INT_MIN / 1 = INT_MIN ok
            # INT_MAX / -1 = INT_MAX not ok
        if dividend == 0:
            return 0
        quo = 0
        negative = (dividend < 0) ^ (divisor < 0) # Works as Negative sign Integer
        divisor = abs(divisor)
        dividend = abs(dividend)

        while dividend >= divisor:
            tempdivisor = divisor
            tempquo = 1
            while dividend >= (tempdivisor << 1):
                # << eta ekta binary operator jeta bit ke left e order deoa ghor onujayi binary te soray
                # example: 2 = 10, << korle hobe 100 = 2 x 2^1 = 4, Zero diye notun ghor ta fill up holo.
                # indirectly eta 2^x er moto kaj kore, 2 = 10, eke <<3 korle tinghor sorbe, so 10000 = 2 x 2^3 = 16
                # <<=, = ta assign kore ager variable tai.
                tempdivisor <<= 1 # Ek ghor bitwise left shift
                # etar mane joto ghor shift toto bar 2 diye multiply holo
                tempquo <<= 1
                # Jehetu tempdivisor = tempquo * divisor
                #jotokhun ota fit hoche tai edike tempquo o sei rate e barche
            # joto khun fit holo totokhun barlo ebar, biyog er pala
            dividend -= tempdivisor
            quo += tempquo
            # ebar jodi bhag korar moto poreo thake next loop e manage hoye jabe
        quo = -quo if negative else quo # Negative er value true hole Negative Quotient return korbe
        return quo