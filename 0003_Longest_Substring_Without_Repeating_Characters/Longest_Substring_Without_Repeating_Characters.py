class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        r = 0 # Right pointer
        l = 0 # Left pointer
        maxlen = 0 # Maximum length
        dc = {} # Dictionary to store Char:Index
        for r, ch in enumerate(s): # R counts Indeces, ch takes elements as input. enumerate helps it to do 
            if ch in dc.keys(): # Checks all keys, wheather ch is already available in the dictionary or not.
                # If available then it means it has been seen before

                if l <= dc[ch]: # Checking if the found duplicate is inside the range or it was passed
                    l = dc[ch] + 1 # Where the last duplicate element was found l will be placed next of that position
                    
            dc[ch] = r # Updating with new position
            rllength = r - l + 1 # Getting the length between R-L pointers
            maxlen = max(rllength, maxlen) # for each iteration comparing the current length with the maximum length

        return maxlen # Returning the maximum length.