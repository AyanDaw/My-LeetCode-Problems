# Check CPP file for explaining comments

class Solution:
    
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return [""]

        res = []
        def paras(current, o, c):
            if len(current) == 2 * n:
                res.append(current)
                return
            
            if o < n:
                paras(current + "(", o + 1, c)

            if c < o:
                paras(current + ")", o, c + 1)
        
        paras("",0,0)
        return res