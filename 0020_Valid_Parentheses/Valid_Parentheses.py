class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        paras = { ")":"(", "}":"{", "]":"["} # I will be asking for opening brackets so those will be in values (check in line 10), and so closes will be in keys.
        for ch in s: # For open brackets
            if ch in paras.values():
                stack.append(ch)

            else: # For close brackets
                if not stack or stack[-1] != paras[ch]:
                    # Not stack means Stack khali? yes!
                    # open na match korle true debe
                    # total condition true hole False trigger korbe 
                    return False
                stack.pop()

        if not stack:
            # Stack khali, tarmane extra kichu pore nei tai true
            return True
        else:
            return False