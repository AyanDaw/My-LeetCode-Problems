class Solution:
    def intToRoman(self, num: int) -> str:
        roman = "" # Answer string
        pos = 0 # Position counter, 0 = ekok, 1 = dosok, 2 = sotok, 3 = hajar.
        dc = {1 : "I", 5 : "V", 10 : "X", 50 : "L", 100 : "C", 500 : "D", 1000 : "M"} # Milestone values
        while (num > 0):
            numLast = num%10 # Last digit katbe
            num = num // 10 # Ekta digit last theke komabo
            
            if numLast == 0:
                # Ei Line ta skip hobe
                pos += 1
                continue
            
            elif numLast < 4:
                # 1, 2, 3
                # 1 er jeta hobe setai baki duto er sathe gun hobe
                temp = dc[10**pos] * numLast
                roman = temp + roman
                
            elif numLast == 4 or numLast == 9:
                # 4, 9
                numLastextra = numLast + 1 # Milestone Value ta
                temp = dc[10**pos] + dc[numLastextra*(10**pos)] # Ek ghor kom er ta age bosbe then milestone value ta
                roman = temp + roman
            elif numLast < 9:
                # 5, 6, 7, 8
                if numLast == 5:
                    temp = dc[5*(10**pos)] # milestone value hole
                    roman = temp + roman
                else:
                    # 6, 7, 8
                    numLastextra = numLast - 5 # Milestone value bad dile je position er 1, 2, 3
                    temp =  dc[5*(10**pos)] + dc[10**pos] * numLastextra
                    roman = temp + roman

            pos += 1

        return roman

# Alternative Solution
# class Solution:
#     def intToRoman(self, num: int) -> str:
#         vals = [
#             (1000,"M"), (900,"CM"), (500,"D"), (400,"CD"),
#             (100,"C"), (90,"XC"), (50,"L"), (40,"XL"),
#             (10,"X"), (9,"IX"), (5,"V"), (4,"IV"), (1,"I")
#         ]
        
#         res = ""
#         for v, s in vals:
#             while num >= v:
#                 res += s
#                 num -= v
#         return res
