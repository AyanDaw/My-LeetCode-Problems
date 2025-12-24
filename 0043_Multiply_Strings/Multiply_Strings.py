class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == 0 or num2 == 0:
            return 0 # Obviously jekono ekta 0 hole multiplication 0 hobe
        upper = len(num1)
        lower = len(num2)
        result = [0] * (upper+lower)
        for i in range(lower-1, -1, -1): #Choto belay jemon gun kortam
            for j in range(upper-1, -1, -1):
                mul = (ord(num1[j]) - ord('0')) * (ord(num2[i]) - ord('0')) # Nicher ekta ke diye baki tinte
                # i = lower - 1, j = upper - 1 at first iteration
                # For the first iteration the rightest element index is: upper+lower-1
                # upper+lower-1 = j+1+i+1-1 = j+i+1
                total = mul + result[j + i + 1] # Ei ghor ta tei current iteration er multiplication ta dhukche
                # Tai ekhane jeta chilo age theke seta + notun ta, for every Multiplication

                result[j + i + 1] = total % 10 # total er ekok er ghor ta.
                result[j + i] += total // 10 # Hather. j+i+1 er just left er ta.
        
        ans = "" # Empty string
        # We will transfer the List's digits into string as it is asked
        
        for digit in result: 
            # Samne theke pechone jachi, samne sob initialized kora 0 gulo thakbe
            if not ans and digit == 0:
                # Ans exist korchena ekhuno but 0 asche tahole skip
                continue  # Directly goes to next iteration
            ans += str(digit) # Int to String conversion

        return ans if ans else "0" 
        # Actually this else condition is never gonna happen as we have already filtered out the ) ans cases
             