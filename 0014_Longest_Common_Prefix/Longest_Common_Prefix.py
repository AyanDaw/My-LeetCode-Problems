class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            # If there is nothing from the start then why should i try, just return the empty string
            return ""

        # Taking the first string of the list of string as starting point.
        prefix = strs[0]
        # later we will compare the rest of the strings

        # Here is not indeces. it is representing every elements/strings of the strs string from index 1
        for s in strs[1:]:

            # This loop will continue until match is found
            while prefix and not s.startswith(prefix):
                # Every time prefix does not matches it reduces one element of the string from the end
                prefix = prefix[:-1]

            if not prefix:
                # If  nothing is left after loop then retun this. else we will compare rest elements with leftover of prefix
                return ""

        return prefix  # If something is left, then returning it
